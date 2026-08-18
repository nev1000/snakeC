#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define SIZE 20

typedef struct {
    int x;
    int y;
} tuple;

typedef struct {
    tuple positions[SIZE * SIZE];
    int length;
} snake;

tuple get_random_tuple();
snake initialize_snake();
void draw_grid(tuple pellet, snake snakey);
snake update_snake(char direc, snake snakey);
char calculate_direc(int ch);
bool check_collision(tuple pellet, tuple head);
void add_body(tuple position, snake* snakey);

tuple get_random_tuple(){
    tuple tup = {1 + rand() % (SIZE - 1), 1 + rand() % (SIZE - 1)};
    return tup;
}

snake initialize_snake(){
    snake snakey;
    snakey.length = 1;
    snakey.positions[0].x = 1;  
    snakey.positions[0].y = 1;
    return snakey;
}

void draw_grid(tuple pellet, snake snakey){
    // for (int i = 0 ; i < snakey.length ; i++){
    //     printw("%d", snakey.positions[i].x);
    //     printw("%d\n", snakey.positions[i].y);
    // }
    attron(COLOR_PAIR(2));
    mvaddch(pellet.y, pellet.x, '#');
    attron(COLOR_PAIR(2));
    for (int i = 0 ; i < snakey.length ; i++){
        attron(COLOR_PAIR(1));
        mvaddch(snakey.positions[i].y, snakey.positions[i].x, 'o');
        attroff(COLOR_PAIR(1));
    }
    for (int i = 0 ; i < SIZE ; i++){
        for (int z = 0 ; z < 2 * SIZE ; z++){
            if (i == 0 || i == SIZE - 1 ){
                mvaddch(i, z, '-');
            } else if (z == 0 || z == 2 * SIZE - 1 ){
                mvaddch(i, z, '|');
            }
        }
    }
    refresh();
}

bool check_collision(tuple pellet, tuple head){
    if (head.x == pellet.x && head.y == pellet.y){
        return true;
    }
    return false;
}

void add_body(tuple position, snake* snakey){
    snakey->length++;
    snakey->positions[snakey->length - 1] = position;
}



snake update_snake(char direc, snake snakey){
    tuple new_positions[SIZE * SIZE];
    int ch = -1;
   
    if (direc == 'd'){
        new_positions[0].x = snakey.positions[0].x;
        new_positions[0].y = snakey.positions[0].y + 1;
    }
    else if (direc == 'u'){
        new_positions[0].x = snakey.positions[0].x;
        new_positions[0].y = snakey.positions[0].y - 1;
    }
    else if (direc == 'l'){
        new_positions[0].x = snakey.positions[0].x - 1;
        new_positions[0].y = snakey.positions[0].y;
    }
    else if (direc == 'r'){
        new_positions[0].x = snakey.positions[0].x + 1;
        new_positions[0].y = snakey.positions[0].y;
    }

    for (int i = 0 ; i + 1 < snakey.length ; i++){
        new_positions[i + 1].x = snakey.positions[i].x;
        new_positions[i + 1].y = snakey.positions[i].y;
    }
     
    for (int i = 0 ; i < snakey.length ; i++){
        snakey.positions[i].x = new_positions[i].x;
        snakey.positions[i].y = new_positions[i].y;
    }

    return snakey;
}

 char calculate_direc(int ch) {
    if (ch == 'd' || ch == KEY_DOWN) return 'd';
    else if (ch == 'u' || ch == KEY_UP) return 'u';
    else if (ch == 'l' || ch == KEY_LEFT) return 'l';
    else if (ch == 'r' || ch == KEY_RIGHT) return 'r';
    return 'q';
}


int main (void){
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    srand(time(NULL));
    tuple pellet = get_random_tuple();
    snake snakey = initialize_snake();
    char direc = 'd';
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    while (true) {
        clear();
        int ch = getch();
        if (ch != ERR){
            direc = calculate_direc(ch);
        }
        bool collision = check_collision(pellet, snakey.positions[0]);
        if (collision){
            add_body(pellet, &snakey);
            pellet = get_random_tuple();   
        }

        snakey = update_snake(direc, snakey);
        draw_grid(pellet, snakey);
        napms(200);
    }
    endwin();
}


  
        
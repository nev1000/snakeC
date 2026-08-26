#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define SIZE 20

void draw_grid(tuple pellet, snake snakey);
bool check_crash(snake* snakey);
void draw_end_game(snake* snakey);
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

void draw_end_game(snake* snakey){
    mvprintw(SIZE / 2, SIZE / 2, "GAME OVER");
    mvprintw(SIZE / 2 + 1, SIZE / 2, "YOU SCORED: %d", snakey->length);
    mvprintw(SIZE / 2 + 3, 0, "\n\n\n\n\n\n\n\n\n");
    refresh();
    napms(900);
    exit(0);
}


int main (void){
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    srand(time(NULL));
    bool game_over = false;
    tuple pellet = get_random_tuple();
    snake snakey = initialize_snake();

    while (!check_tuple_valid(pellet, &snakey)){
        pellet = get_random_tuple();
    }

    char direc = 'd';
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    while (true) {
        clear();
        int ch = getch();
        if (ch != ERR){
            direc = calculate_direc(direc, ch);
        }
        if (snakey.length > 1){
        bool collision = check_collision(&snakey);
        if (collision){
            exit(0);
        }
        }
        bool eaten = check_pellet_eaten(pellet, snakey.positions[0]);
        if (eaten){
            add_body(pellet, &snakey);
            while (!check_tuple_valid(pellet, &snakey)){
                pellet = get_random_tuple();
            }   
        }
        bool crash = check_crash(&snakey);
        if (crash){
            game_over = true;
        }
        if (game_over){
            draw_end_game(&snakey);
        }
        snakey = update_snake(direc, snakey);
        draw_grid(pellet, snakey);
        napms(200);
    }
    endwin();
}


  
        
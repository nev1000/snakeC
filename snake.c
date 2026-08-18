    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <ncurses.h>

    int SIZE = 20;

    typedef struct {
        int x;
        int y;
    } tuple;

    typedef struct {
        tuple positions[20 * 20];
        int length;
    } snake;

    void print_grid(tuple pellet_location, tuple snake_location[]);
    tuple get_rand_number();
    bool check_snake(int pos_x, int pos_y, tuple positions[]);
    void update_snake(snake* snakey, char direction);
    bool check_collision(tuple pellet_location, tuple snakey_head);


    int main (void){   
         // ---- ncurses setup: this is what was missing ----
    initscr();              // take over the terminal; REQUIRED before any getch()
    cbreak();               // deliver keys immediately, no waiting for Enter
    noecho();               // don't print the keys the user presses
    keypad(stdscr, TRUE);   // makes KEY_RIGHT etc. work as single values
    curs_set(0);            // hide the blinking cursor
    timeout(50);           // getch() waits at most 500 ms -> replaces usleep()
    // ----- 
        char direc = 'd';
        tuple location = get_rand_number();
        tuple snake_starting_position = {1, 1};
        tuple snake_starting_position_1 = {2, 2};
        tuple snake_starting_position_2 = {3, 2};
        snake snakey;
        snakey.length = 0;
        for (int i = 0 ; i < 400 ; i++){
            snakey.positions[i].x = 0;
            snakey.positions[i].y = 0;
        }
        snakey.positions[0] = snake_starting_position;
        snakey.positions[1] = snake_starting_position_1;
        snakey.positions[2] = snake_starting_position_2;
        snakey.length = 3;
        // print_grid(location, snakey.positions);
        // char input;
        // scanf("%c", &input);
        // if (input == 'd'){
        //     for (int i = 0 ; i < 400 ; i++){
        //         if (snakey.positions[i].x == 0 && snakey.positions[i].y == 0){
        //             snakey.positions[i].x = snakey.positions[i - 1].x + 1;
        //             snakey.positions[i].y = snakey.positions[i - 1].y;
        //             snakey.positions[0].x = -1;
        //             snakey.positions[0].y = -1;
        //             break;
        //         }
        //     }
        // }
        while (true){
            int ch = getch();   // ← this line is the "background listening"
            if (ch == 'd' || ch == KEY_DOWN) direc = 'd';
            if (ch == 'u' || ch == KEY_UP) direc = 'u';
            if (ch == 'l' || ch == KEY_LEFT) direc = 'l';
            if (ch == 'r' || ch == KEY_RIGHT) direc = 'r';
            printw("THIS IS THE DIRECTION: %c", direc);
            update_snake(&snakey, direc);
            clear();
            printw("location: %d %d\n", location.x, location.y);
            printw("location: %d %d\n", snakey.positions[snakey.length - 1].x, snakey.positions[snakey.length - 1].y);
            if (check_collision(location, snakey.positions[snakey.length - 1])){
             printw("HEREHEREHRHERHERHEHRH!!!!");
             tuple location = get_rand_number();
            } 
            print_grid(location, snakey.positions);
            refresh();
            usleep(500000);   // 200,000 microseconds = 0.2 seconds
        }
    }

    tuple get_rand_number(){
        srand(time(NULL));
        tuple tup = {2 + rand() % (SIZE - 2), 2 + rand() % (SIZE - 2)};
        return tup;
    }

    bool check_snake(int pos_x, int pos_y, tuple positions[]){
    for (int i = 0 ; i < SIZE * SIZE ; i++){
        if (positions[i].x == pos_x && positions[i].y == pos_y){
            return true;
        }
    }
    return false;
}

    void update_snake(snake* snakey, char direction){
        if (direction == 'r'){
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x == 0 && snakey->positions[i].y == 0){
                    snakey->positions[i].x = snakey->positions[i - 1].x + 1;
                    snakey->positions[i].y = snakey->positions[i - 1].y;
                    break;
                }
            }
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x != -1 && snakey->positions[i].y != -1){
                    snakey->positions[i].x = -1;
                    snakey->positions[i].y = -1;
                    break;
                }
        }
    }
      if (direction == 'd'){
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x == 0 && snakey->positions[i].y == 0){
                    snakey->positions[i].x = snakey->positions[i - 1].x;
                    snakey->positions[i].y = snakey->positions[i - 1].y + 1;
                    break;
                }
            }
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x != -1 && snakey->positions[i].y != -1){
                    snakey->positions[i].x = -1;
                    snakey->positions[i].y = -1;
                    break;
                }
        }
    }


    if (direction == 'l'){
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x == 0 && snakey->positions[i].y == 0){
                    snakey->positions[i].x = snakey->positions[i - 1].x - 1;
                    snakey->positions[i].y = snakey->positions[i - 1].y;
                    break;
                }
            }
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x != -1 && snakey->positions[i].y != -1){
                    snakey->positions[i].x = -1;
                    snakey->positions[i].y = -1;
                    break;
                }
        }
    }


    if (direction == 'u'){
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x == 0 && snakey->positions[i].y == 0){
                    snakey->positions[i].x = snakey->positions[i - 1].x;
                    snakey->positions[i].y = snakey->positions[i - 1].y - 1;
                    break;
                }
            }
            for (int i = 0 ; i < 400 ; i++){
                if (snakey->positions[i].x != -1 && snakey->positions[i].y != -1){
                    snakey->positions[i].x = -1;
                    snakey->positions[i].y = -1;
                    break;
                }
        }
    }
}

bool check_collision(tuple pellet_location, tuple snakey_head){
    return pellet_location.x == snakey_head.x && pellet_location.y == snakey_head.y;
}

void print_grid(tuple pellet_location, tuple snake_location[]){
        for (int i = 0 ; i < SIZE ; i++){
                for (int z = 0 ; z < 2 * SIZE ; z++){
                    if (i != 0 && i != SIZE - 1){
                        if (z == 0 || z == 2 * SIZE - 1){
                            printw(".");
                        } else {
                            if (pellet_location.x == i && pellet_location.y == z){
                                printw("*");
                            } else if (check_snake(z, i, snake_location)){
                                printw("o");
                            } } else if (check_snake(z, i, snake_location)){
                                printw("o");
                            } else {
                                printw(" ");   
                            }
                        }
                    } else {
                        printw(".");
                    }
                }
            printw("\n");
        }
    


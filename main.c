#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "draw.h"
#include "food.h"
#include "snake.h"

#define SIZE 20

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


  
        
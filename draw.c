#include "draw.h"
#include <ncurses.h>
#define SIZE 20


void draw_end_game(snake* snakey){
    mvprintw(SIZE / 2, SIZE / 2, "GAME OVER");
    mvprintw(SIZE / 2 + 1, SIZE / 2, "YOU SCORED: %d", snakey->length);
    mvprintw(SIZE / 2 + 3, 0, "\n\n\n\n\n\n\n\n\n");
    refresh();
    napms(900);
    exit(0);
}

void draw_grid(tuple pellet, snake* snakey){
    // for (int i = 0 ; i < snakey.length ; i++){
    //     printw("%d", snakey.positions[i].x);
    //     printw("%d\n", snakey.positions[i].y);
    // }
    attron(COLOR_PAIR(2));
    mvaddch(pellet.y, pellet.x, '#');
    attron(COLOR_PAIR(2));
    for (int i = 0 ; i < snakey->length ; i++){
        attron(COLOR_PAIR(1));
        mvaddch(snakey->positions[i].y, snakey->positions[i].x, 'o');
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
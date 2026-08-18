#include <ncurses.h>

int main(void){
    initscr();                    // enter ncurses mode, take over the screen
    printw("Hello, world!");      // like printf, draws at the cursor
    refresh();                    // actually push changes to the screen
    getch();                      // wait for a keypress
    endwin();                     // restore normal terminal — never skip this
    return 0;
}
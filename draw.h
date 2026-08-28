#ifndef DRAW_H
#define DRAW_H
#include <stdlib.h>
#include "snake.h"
#include "tuple.h"

void draw_grid(tuple pellet, snake snakey);
void draw_end_game(snake* snakey);

#endif

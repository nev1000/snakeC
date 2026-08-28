#ifndef SNAKE_H
#define SNAKE_H
#define SIZE 20
#include <stdbool.h>
#include "tuple.h"

typedef struct {
    tuple positions[SIZE * SIZE];
    int length;
} snake;

snake initialize_snake();
snake update_snake(char direc, snake snakey);
bool check_collision(snake* snakey);
char calculate_direc(char direc, int ch);
void add_body(tuple position, snake* snakey);
bool check_crash(snake* snakey);

#endif

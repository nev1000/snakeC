#ifndef SNAKE_H
#define SNAKE_H
#define SIZE 20
#include <stdbool.h>
#include "tuple.h"

typedef struct {
    tuple* positions; //we are going to have a pointer to a tuple called positions - then malloc decides how many tuples it points at
    int length;
} snake;

snake* initialize_snake();
void update_snake(char direc, snake* snakey);
bool check_collision(snake* snakey);
char calculate_direc(char direc, int ch);
void add_body(tuple position, snake* snakey);
bool check_crash(snake* snakey);

#endif

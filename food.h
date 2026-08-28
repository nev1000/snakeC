#ifndef FOOD_H
#define FOOD_H
#include <stdbool.h>
#include "snake.h"
#include "tuple.h"

bool check_tuple_valid(tuple tup, snake* snakey);
bool check_pellet_eaten(tuple pellet, tuple head);
tuple get_random_tuple();

#endif

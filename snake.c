#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int SIZE = 20;

typedef struct {
    int x;
    int y;
} tuple;

typedef struct {
    tuple positions[20 * 20];
} snake;

void print_grid(tuple pellet_location, tuple snake_location[]);
tuple get_rand_number();
bool check_snake(int pos_x, int pos_y, tuple positions[]);

int main (void){   
    tuple location = get_rand_number();
    tuple snake_starting_position = {1, 1};
    tuple snake_starting_position_1 = {2, 2};
    snake snakey;
    snakey.positions[0] = snake_starting_position;
    snakey.positions[1] = snake_starting_position_1;
    print_grid(location, snakey.positions);
}

tuple get_rand_number(){
    srand(time(NULL));
    tuple tup = {2 + rand() % (SIZE - 2), 2 + rand() % (SIZE - 2)};
    return tup;
}

//comment 

bool check_snake(int pos_x, int pos_y, tuple positions[]){
    for (int i = 0 ; i < SIZE * SIZE ; i++){
        if (positions[i].x == pos_x && positions[i].y == pos_y){
            return true;
        } else {
            continue;
        }
    }
    return false;
}

void print_grid(tuple pellet_location, tuple snake_location[]){
    for (int i = 0 ; i < SIZE ; i++){
            for (int z = 0 ; z < 2 * SIZE ; z++){
                if (i != 0 && i != SIZE - 1){
                    if (z == 0 || z == 2 * SIZE - 1){
                        printf(".");
                    } else {
                        if (pellet_location.x == i && pellet_location.y == z){
                            printf("*");
                        } else if (check_snake(i, z, snake_location)){
                            printf("o");
                        } else {
                            printf(" ");   
                        }
                    }
                } else {
                    printf(".");
                }
            }
        printf("\n");
    }
}


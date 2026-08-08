#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} tuple;

typedef struct {
    tuple positions[SIZE * SIZE];
} snake;

void print_starting_grid(tuple location);
tuple get_rand_number();
int SIZE = 20;

int main (void)
{   
    tuple location = get_rand_number();
    print_starting_grid(location);
}

tuple get_rand_number(){
    srand(time(NULL));
    tuple tup = {2 + rand() % (SIZE - 2), 2 + rand() % (SIZE - 2)};
    return tup;
}

void print_starting_grid(tuple location){
    printf("%d, %d\n", location.x, location.y);
    for (int i = 0 ; i < SIZE ; i++){
            for (int z = 0 ; z < 2 * SIZE ; z++){
                if (i != 0 && i != SIZE - 1){
                    if (z == 0 || z == 2 * SIZE - 1){
                        printf(".");
                    } else {
                        if (location.x == i && location.y == z){
                            printf("*");
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


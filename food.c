#include "food.h"
#define SIZE 20
#include <stdlib.h>

bool check_tuple_valid(tuple tup, snake* snakey){
    for (int i = 0 ; i < snakey->length ; i++){
        if (snakey->positions[i].x == tup.x && snakey->positions[i].y == tup.y){
            return false;
        }
    } 
    // FILE* debug = fopen("debug.txt", "a");
    // if (debug == NULL) {
    //     printf("Couldn't open file!");
    //     return false;
    // }
    // fprintf(debug, "Pellet: %d %d\n", tup.x, tup.y);
    
    // for (int i = 0 ; i < snakey->length ; i++){
    //     fprintf(debug, "Snake: %d %d\n", snakey->positions[i].x, snakey->positions[i].y);
    // }
    // fflush(debug);
    // fclose(debug);
    return true;
}

tuple get_random_tuple(){
    tuple tup = {1 + rand() % (SIZE - 2), 1 + rand() % (SIZE - 2)};
    return tup;
}

bool check_pellet_eaten(tuple pellet, tuple head){
    if (head.x == pellet.x && head.y == pellet.y){
        return true;
    }
    return false;
}
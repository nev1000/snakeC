#include <stdio.h>

void print_grid(void);

int main (void)
{
    print_grid();
}

void print_grid(){
    for (int i = 0 ; i < 8 ; i++){
        for (int z = 0 ; z < 8 ; z++){
            printf("*");
        }
        printf("\n");
    }
}


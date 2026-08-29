#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int* p = malloc(sizeof(int)); //give me space to hold an integer;
    *p = 42; //go to that address and put 42 there;
    printf("%d\n", *p);
    return 0;
}

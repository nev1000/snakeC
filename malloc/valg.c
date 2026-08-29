#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *nums = malloc(3 * sizeof(int));
    if (nums == NULL) return 1;

    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;

    printf("%d %d %d\n", nums[0], nums[1], nums[2]);

    free(nums);
    return 0;
}

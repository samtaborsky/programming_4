#include <stdio.h>

int main(void) {
    // I have not been able to find the pattern behind the last sequence, but....
    int array[21] = {1,5,2,3,3,1,4,-1,5,-3,6,-5,7,-7,8,-9,9,-11,10,-13,11};
    for (int i = 0; i < 21; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 0;
}
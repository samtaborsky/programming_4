#include <stdio.h>

int main(void) {
    int a = 2;
    for (int i = 1; i < 30; i += 2) {
        printf("%d, %d, ", i, a);
        a += 4;
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

int main(void) {
    int a = 1;
    printf("%d, ", a);
    for (int i = 1; i < 20; ++i) {
        printf("%d, ", a+i);
        a = a + i;
    }
    printf("\n");
    return 0;
}
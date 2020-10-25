#include <stdio.h>
int main() {
    int x1 = 0, x2 = 1, next_x;
    for (int i = 0; i < 10; ++i) {
        printf("%d, ", x1);
        next_x = x1 + x2;
        x1 = x2;
        x2 = next_x;
    }
    printf("\n");
    return 0;
}
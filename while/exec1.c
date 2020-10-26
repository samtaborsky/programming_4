#include <stdio.h>

int main(void) {
    int sum = 0, n = 2493;

    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }

    printf("%d\n", sum);

    return 0;
}
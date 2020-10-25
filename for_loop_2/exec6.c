#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter the number N (N <= 1): ");
    scanf("%d", &n);
    if (n >= 1) {
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
        printf("%d\n", sum);
    }
    else {
        printf("%d is not equal or greater than 1.\n", n);
    }
    return 0;
}
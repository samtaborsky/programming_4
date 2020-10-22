#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);
    if (a < b) {
        if (a % 2 == 0) {
            for (int i = a; i <= b; i += 2) {
                printf("%d, ", i);
            }
        }
        else {
            for (int i = a + 1; i <= b; i += 2) {
                printf("%d, ", i);
            }
        }
    }
    else if (b < a) {
        if (b % 2 == 0) {
            for (int i = b; i <= a; i += 2) {
                printf("%d, ", i);
            }
        }
        else {
            for (int i = b + 1; i <= a; i += 2) {
                printf("%d, ", i);
            }
        }
    }
    else if (a == b) {
        printf("The numbers are equal.");
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);
    if (a < b) {
        if (a % 2 == 0) {
            for (a; a <= b; a += 2) {
                printf("%d, ", a);
            }
        }
        else {
            a++;
            for (a; a <= b; a += 2) {
                printf("%d, ", a);
            }
        }
    }
    else if (b < a) {
        if (b % 2 == 0) {
            for (b; b <= a; b += 2) {
                printf("%d, ", b);
            }
        }
        else {
            b++;
            for (b; b <= a; b += 2) {
                printf("%d, ", b);
            }
        }
    }
    else {
        printf("The numbers are equal.\n");
    }
    printf("\n");
    return 0;
}
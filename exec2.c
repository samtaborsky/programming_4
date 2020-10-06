#include <stdio.h>

int main() {
    int a = 0;
    printf("Enter an integer: ");
    scanf("%d", &a);
    if (a % 2 == 0) {
        printf("The integer is even.\n");
    }
    else {
        printf("The integer is odd.\n");
    }
    return 0;
}


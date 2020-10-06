#include <stdio.h>

int main() {
    int a = 0, last = 0;
    printf("Enter an integer: ");
    scanf("%d", &a);
    last = a % 10;
    if (last >= 0 && last <= 4) {
        printf("The last digit %d is from range 0-4\n", last);
    }
    else {
        printf("The last digit %d is from range 5-9\n", last);
    }
    return 0;
}


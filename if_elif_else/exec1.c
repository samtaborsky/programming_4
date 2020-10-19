#include <stdio.h>

int main() {
    int a = 0, b = 0;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("The two integers are equal.\n");
    }
    else {
        printf("They are not equal.\n");
    }
    return 0;
}

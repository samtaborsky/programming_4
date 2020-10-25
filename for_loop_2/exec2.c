#include <stdio.h>

int main(void) {
    int n = 0;
    printf("Enter the length N: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("*");
    }
    printf("\n");
    return 0;
}
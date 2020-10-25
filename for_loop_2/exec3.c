#include <stdio.h>

int main(void) {
    int n = 0;
    char c;
    printf("Enter the length N: ");
    scanf("%d", &n);
    getchar();
    printf("Enter a character: ");
    scanf("%c", &c);
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
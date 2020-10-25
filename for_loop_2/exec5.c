#include <stdio.h>

int main(void) {
    int m, n;
    printf("Enter the boundaries M and N: ");
    scanf("%d %d", &m, &n);
    if (m < n) {
        for (int i = m; i <= n; ++i) {
            if (i % 7 == 0) {
                printf("%d, ", i);
            }
        }
    }
    else if (n < m) {
        for (int i = n; i <= m; ++i) {
            if (i % 7 == 0) {
                printf("%d, ", i);
            }
        }
    }
    else if (m == n) {
        printf("The numbers are equal.");
    }
    printf("\n");
    return 0;
}
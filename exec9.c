#include <stdio.h>

int main() {
    double a = 0, b = 0, c = 0;
    printf("Enter the sides a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == b && b == c) {
        printf("The triangle is Equilateral.\n");
    }
    else if (a == b || a == c || b == c) {
        printf("The triangle is Isosceles.\n");
    }
    else {
        printf("The triangle is Scalene.\n");
    }

    return 0;
}

#include <math.h>
#include <stdio.h>

int main() {
    long double a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b, c: ");
    scanf("%Lf %Lf %Lf", &a, &b, &c);

    discriminant = b*b - (4*a*c);

    // check if this is a quadratic equation
    if (a == 0) {
        printf("This is not a quadratic equation");
    }

    if (discriminant > 0){
        root1 = (-b + sqrtl(discriminant)) / (2*a);
        root2 = (-b - sqrtl(discriminant)) / (2*a);
        printf("Root 1 = %.2Lf\nRoot 2 = %.2Lf\n", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = root2 = -b / (2*a);
        printf("Root 1 = Root 2 = %.2Lf\n", root1);
    }
    // complex and not real roots
    else {
        printf("The roots are complex and not real numbers\n");
    }

    return 0;
}
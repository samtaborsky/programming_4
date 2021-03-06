// I have found out that the problem with math.h was that the compiler does not
// automatically link the shared object file (libm.so) which contains the implementations
// of the math.h functions to the executable -- solved by passing the -lm flag to the compiler
// P.S.: an interesting read on this topic : https://bit.ly/36OJoFx (StackOverflow)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    long double a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b, c: ");
    scanf("%Lf %Lf %Lf", &a, &b, &c);

    discriminant = b*b - 4*a*c;

    // check if this is a quadratic equation
    if (a == 0) {
        printf("This is not a quadratic equation\n");
        exit(1);
    }

    if (discriminant > 0){
        root1 = (-b + sqrtl(discriminant)) / (2*a);
        root2 = (-b - sqrtl(discriminant)) / (2*a);
        printf("Root 1 = %.2Lf\nRoot 2 = %.2Lf\n", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = -b / (2*a);
        printf("Root 1 = Root 2 = %.2Lf\n", root1);
    }
    // complex and not real roots
    else {
        printf("The roots are complex and not real numbers\n");
    }

    return 0;
}
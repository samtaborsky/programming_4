#include <stdio.h>

int main() {
    int number1 = 0, number2 = 0, number3 = 0;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &number1, &number2, &number3);

    if (number1 > number2 && number1 > number3) {
        printf("Number 1 (%d) is the largest\n", number1);
    }

    else if (number2 > number1 && number2 > number3) {
        printf("Number 2 (%d) is the largest\n", number2);
    }

    else if (number3 > number1 && number3 > number2) {
        printf("Number 3 (%d) is the largest\n", number3);
    }

    else if (number1 == number2 && number2 == number3) {
        printf("All numbers are equal\n");
    }
    return 0;
}
/*
 * Author: Samuel Táborský
 * Last revision: 7.6.2021
 *
 * Program 1
 *
 * This program:
 * - reads 2 integers from STDIN
 * - calculates and displays their GCD
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    int number1, number2;
    // input
    printf("Enter 2 numbers: ");
    scanf("%d %d", &number1, &number2);

    // gcd calculation
    int a = number1, b = number2, c;
    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }

    // output
    printf("%d\n", a);

    return 0;
}
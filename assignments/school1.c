#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void printbinary(int number, int bits) {
    char array[bits];
    int length = bits;
    while (number != 0) {
        array[bits-1] = number % 2;
        number /= 2;
        bits--;
    }
    bits--;
    for (int i = bits; i >= 0; i--) {
        array[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main(void) {
    int number1, number2;
    printbinary(16383, 16);
    printf("Enter number 1: ");
    scanf("%d", &number1);
    printf("Enter number 2: ");
    scanf("%d", &number2);


     return 0;
}


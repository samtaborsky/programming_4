#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void printbinary(int number) {
    for (int i = sizeof(number) * 8 - 1; i >= 0; i--){printf("%d", number >> i & 1);}; printf("\n");
}

int main(void) {
    int shift;
    int number1 = 63;
    printf("Enter which bit u want to clear: ");
    scanf("%d", &shift);
    printbinary(number1);
    int output = number1 ^ (1 << shift);
    printbinary(output);
    return 0;
}
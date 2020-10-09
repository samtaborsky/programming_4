#include <stdio.h>

int main() {
    int year = 0;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (year % 400 == 0) {
        printf("Year is leap\n");
    }
    else if (year % 100 == 0) {
        printf("Year is not leap\n");
    }
    else if (year % 4 == 0) {
        printf("Year is leap\n");
    }
    else {
        printf("Year is not leap\n");
    }
    return 0;
}


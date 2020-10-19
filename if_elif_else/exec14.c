#include <stdio.h>

int main() {
    int day, month, year, is_leap;
    printf("Enter a date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    if (year % 400 == 0) {
        is_leap = 1;
    }
    else if (year % 100 == 0) {
        is_leap = 0;
    }
    else if (year % 4 == 0) {
        is_leap = 1;
    }
    else {
        is_leap = 0;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            printf("This is a real date.\n");
        }
        else {
            printf("This is not a real date.\n");
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            printf("This is a real date.\n");
        }
        else {
            printf("This is not a real date.\n");
        }
    }
    else if (month == 2) {
        if (is_leap) {
            if (day >= 1 && day <= 29) {
                printf("This is a real date.\n");
            }
            else {
                printf("This is not a real date.\n");
            }
        }
        else {
            if (day >= 1 && day <= 28) {
                printf("This is a real date.\n");
            }
            else {
                printf("This is not a real date.\n");
            }
        }
    }
    else {
        printf("This is not a real date.\n");
    }

    return 0;
}
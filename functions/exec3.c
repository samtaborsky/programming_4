#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int get_dow_1(int m,int d,int y){y-= m < 3;return (y + y / 4 - y / 100 + y / 400 + "-bed=pen+mad."[m] + d) % 7;}
// I just had to include this function, it is so awesome

int get_dow(int day, int month, int year) {
    if (month == 2) {
        month = 14;
        year--;
    }
    else if (month == 1) {
        month = 13;
        year--;
    }

    int day_of_week, cent, zero_based_cent;
    cent = year % 100;
    zero_based_cent = year / 100;
    day_of_week = (day + ((13*(month+1))/5) + cent + (cent/4) + (zero_based_cent/4) + 5*zero_based_cent) % 7;

    if (day_of_week < 0 || day_of_week > 6) {
        day_of_week = 0;
    }
    else if (day_of_week == 0) {
        day_of_week = 6;
    }
    else if (day_of_week == 1) {
        day_of_week = 7;
    }
    else if (day_of_week == 2) {
        day_of_week = 1;
    }
    else if (day_of_week == 3) {
        day_of_week = 2;
    }
    else if (day_of_week == 4) {
        day_of_week = 3;
    }
    else if (day_of_week == 5) {
        day_of_week = 4;
    }
    else if (day_of_week == 6) {
        day_of_week = 5;
    }
    return day_of_week;
}

int main(void) {
    int day, month, year, dow;
    printf("Enter the day of the month (1-31): ");
    scanf("%d", &day);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    dow = get_dow(day, month, year);
    if (dow == 1) {
        printf("Monday\n");
    }
    else if (dow == 2) {
        printf("Tuesday\n");
    }
    else if (dow == 3) {
        printf("Wednesday\n");
    }
    else if (dow == 4) {
        printf("Thursday\n");;
    }
    else if (dow == 5) {
        printf("Friday\n");
    }
    else if (dow == 6) {
        printf("Saturday\n");
    }
    else if (dow == 7) {
        printf("Sunday\n");
    }
    else if (dow == 0) {
        printf("An error occured\n");
    }
    return 0;
}
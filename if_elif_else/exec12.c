#include <stdio.h>

int main() {
    int id = 0;
    double units = 0, cost = 0;
    char name[100];

    printf("Enter your Customer ID: ");
    scanf("%d", &id);
    getchar();
    printf("Enter your name: ");
    fgets(name, 100, stdin);
    printf("Enter the units consumed: ");
    scanf("%lf", &units);

    if (units < 200) {
        cost = units * 1.2;
    }
    else if (units >= 200 && units < 400) {
        cost = units * 1.5;
    }
    else if (units >= 400 && units < 600) {
        cost = units * 1.8;
    }
    else {
        cost = units * 2;
    }

    printf("\nCustomer ID: %d\n"
           "Name: %s"
           "Amount to pay: %lf\n", id, name, cost);

    return 0;
}
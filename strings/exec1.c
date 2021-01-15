#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX];
    char str_orig[MAX];
    char *token = NULL;
    int part = 0;
    int check = 0;

    printf("Enter the address you want to check: ");
    scanf("%s", str);
    strcpy(str_orig, str);

    token = strtok(str, ".");
    while (token != NULL) {
        part = atoi(token);
        if (part < 256) {
            check++;
        }
        token = strtok(NULL, ".");
    }

    if (check == 4) {
        printf("%s is a valid IPV4 address.\n", str_orig);
    }
    else {
        printf("%s is not a valid IPV4 address.\n", str_orig);
    }

    return 0;
}
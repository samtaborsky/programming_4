#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "";
    int letters = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
            letters++;
        }
        else if (str[i] >= 48 && str[i] <= 57) {
            digits++;
        }
        else {
            special++;
        }
    }

    printf("Letters: %d\n"
           "Digits: %d\n"
           "Special characters: %d\n", letters, digits, special);

    return 0;
}
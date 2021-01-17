#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "", visited_char[MAX] = "";
    int count[MAX] = {};
    int visited_pos = 0, check = 0, largest = 0, repeated = 0;

    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) { // The first iteration will log the character automatically
            visited_char[visited_pos] = str[i];
            count[visited_pos]++;
            visited_pos++;
        }
        else if (str[i] == 0 || str[i] == 9 || str[i] == 32) { // skip the count if character is space
            continue;
        }
        else {
            for (int n = 0; n < visited_pos; n++) { // if the character is already saved, count++ with its position
                if (str[i] == visited_char[n]) {
                    count[n]++;
                    check = 1; // to see if the loop found the character in visited_char array
                }
            }
            if (check == 0) { // if not, add it and count++ with its position
                visited_char[visited_pos] = str[i];
                count[visited_pos]++;
                visited_pos++;
            }
            else {
                check = 0; // reset the check
            }
        }
    }

    for (int i = 0; i < strlen(visited_char); i++) { // find the largest number of uses
        if (largest < count[i]) {
            largest = count[i];
        }
    }
    for (int i = 0; i < strlen(visited_char); i++) { // find if there are more symbols with the same count
        if (largest == count[i]) {
            repeated++;
        }
    }
    if (repeated == 1) {
        for (int i = 0; i < strlen(visited_char); i++) {
            if (count[i] == largest) {
                printf("The most used symbol is %c, it has been used %d times.\n", visited_char[i], largest);
            }
        }
    }
    else {
        printf("The most used characters are: (symbol - count)\n");
        for (int i = 0; i < strlen(visited_char); i++) {
            if (count[i] == largest) {
                printf("%c - %d\n", visited_char[i], largest);
            }
        }
    }

    return 0;
}
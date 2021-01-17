#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "";
    int i;

    printf("Enter a string: ");
    // This is a check for the trailing newline char you get with fgets() and which messes up the count.
    // It uses strlen(), but it is the best way to remove that \n char.
    // In most cases, strtok(str, "\n") can be used, but when the input is just a newline char, it does not work
    // and the program outputs the length as 1.
    if (fgets(str, MAX, stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }

    for (i = 0; str[i] != '\0'; ++i);

    printf("The length of the string is %d.\n", i);

    return 0;
}
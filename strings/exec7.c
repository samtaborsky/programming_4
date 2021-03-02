#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "";
    char substr[MAX] = "";
    char case_check;
    char *token = NULL;
    int count_w = 0, count_wo = 0;

    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }
    printf("Substring to be found: ");
    if (fgets(substr, MAX, stdin) != NULL) {
        int len = strlen(substr);
        if (len > 0 && substr[len - 1] == '\n') {
            substr[len - 1] = '\0';
        }
    }
    printf("Case sensitive? (y/n): ");
    scanf("%c", &case_check);

    if (case_check == 78 || case_check == 110) { // case insensitive
        // without overlapping
        token = strtok(str, substr);
        while (token != NULL) {
            count_wo++;
            token = strtok(NULL, substr);
        }




    }

    else if (case_check == 89 || case_check == 121) { // case sensitive

    }

    return 0;
}
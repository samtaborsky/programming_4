#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "";
    char character;
    char case_check;
    int count = 0, pos_count = 0;

    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
        }
    }
    printf("Character to be found: ");
    scanf("%c", &character);
    getchar();
    printf("Case-sensitive? (y/n): ");
    scanf("%c", &case_check);

    int positions[strlen(str)];

    if (case_check == 89 || case_check == 121) { // case sensitive
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == character) {
                count++;
                positions[pos_count] = i;
                pos_count++;
            }
        }
    }
    else if (case_check == 78 || case_check == 110) { // case insensitive
        if (character >= 65 && character <= 90) {
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == character || str[i] == character + 32) {
                    count++;
                    positions[pos_count] = i;
                    pos_count++;
                }
            }
        }
        else if (character >= 97 && character <= 122) {
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == character || str[i] == character - 32) {
                    count++;
                    positions[pos_count] = i;
                    pos_count++;
                }
            }
        }
    }

    printf("The letter %c has been found %d times at position(s) ", character, count);
    for (int i = 0; i < pos_count - 1; i++) {
        printf("%d, ", positions[i]);
    }
    printf("%d.\n", positions[pos_count-1]);

    return 0;
}
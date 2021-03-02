#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int check_expression(char string[MAX]) {
    int open_br = 0, closed_br = 0, flag = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == 40) {
            open_br++;
        }
        else if (string[i] == 41) {
            closed_br++;
        }
    }
    if (open_br == closed_br) {
        flag = 0;
    }
    else if (open_br > closed_br) {
        flag = 1;
    }
    else if (open_br < closed_br) {
        flag = 2;
    }
    return flag;
}


int main(void) {
    char string[MAX];
    printf("Enter the expression to check: ");
    fgets(string, MAX, stdin);
    strtok(string, "\n");
    int check_f = check_expression(string);
    if (check_f == 0) {
        printf("%s -- OK\n", string);
    }
    else if (check_f == 1) {
        printf("%s -- too many open brackets\n", string);
    }
    else if (check_f == 2) {
        printf("%s -- too many closed brackets\n", string);
    }
    return 0;
}

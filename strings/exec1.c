#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char str[MAX] = "";
    char str_orig[MAX] = "";
    char *token = NULL;
    int part = 0;
    int check = 0;

    printf("Enter the address you want to check: ");
    scanf("%s", str);
    strcpy(str_orig, str);
    // TODO: finish code to repair wrong inputs
//    if (str[0] == 46) {
//        str[0] = '\0';
//    }
    if (str[0] == 46) {
        printf("%s is not a valid IPV4 address.\n", str_orig);
        exit(0);
    }
//    for (int i = 0; i < strlen(str); ++i) {
//        if (str[i] == 46 && str[i+1] == 46) {
//            for (int n = 0; n < (strlen(str)-i); n++) {
//                str[i+n] = str[i+n+1];
//            }
//        }
//    }
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 46 && str[i+1] == 46) {
            printf("%s is not a valid IPV4 address.\n", str_orig);
            exit(0);
        }
    }

    token = strtok(str, ".");
    while (token != NULL) {
        part = atoi(token);
        if (part < 256 && part >= 0) {
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
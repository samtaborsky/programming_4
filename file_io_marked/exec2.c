#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main(void) {
    FILE *input, *output;
    char *location, *name, *full_location;
    int len, mode, character, shift;

    // I was reading about memory allocation and I thought I'd try it this way
    location = (char*) malloc(MAX);
    name = (char*) malloc(MAX);
    full_location = (char*) malloc(MAX*2);

    printf("Location: ");
    if (fgets(location, MAX, stdin) != NULL) {
        int len_tmp = strlen(location);
        if (len_tmp > 0 && location[len_tmp - 1] == '\n') {
            location[len_tmp - 1] = '\0';
        }
    }
    len = strlen(location);
    if (location[len-1] != 47) {
        strcat(location, "/");
    }
    if (len >= 1) {
        strcat(full_location, location);
    }

    printf("Name: ");
    if (fgets(name, MAX, stdin) != NULL) {
        int len_tmp = strlen(name);
        if (len_tmp > 0 && name[len_tmp - 1] == '\n') {
            name[len_tmp - 1] = '\0';
        }
    }
    strcat(full_location, name);

    do {
        printf("1) Encryption\n2) Decryption\nWhat mode would you like to use (1-2): ");
        scanf("%d", &mode);
    }
    while (mode != 1 && mode != 2);

    do {
        printf("Choose shift number (1-26): ");
        scanf("%d", &shift);
    }
    while (shift <= 1 && shift >= 26);

    input = fopen(full_location, "r");
    if (input == NULL) {
        printf("The input file could not be opened, exiting...\n");
        return EXIT_FAILURE;
    }

    if (mode == 1) {
        output = fopen("encrypted.txt", "w");
        if (output == NULL) {
            printf("The output file could not be opened, exiting...\n");
            return EXIT_FAILURE;
        }

        while ((character = fgetc(input)) != EOF) {
            if (isalpha(character)) {
                if (islower(character)) {
                    char temp = (((character - 97)+shift)%26)+97;
                    if(temp > 122) {
                        temp -= 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
                else if (isupper(character)) {
                    char temp = (((character - 65)+shift)%26)+65;
                    if(temp > 90){
                        temp -= 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
            }
            else {
                fputc(character, output);
                fputc(character, stdout);
            }
        }
        printf("\n");
    }

    else {
        output = fopen("decrypted.txt", "w");
        if (output == NULL) {
            printf("The output file could not be opened, exiting...\n");
            return EXIT_FAILURE;
        }

        while ((character = fgetc(input)) != EOF) {
            if (isalpha(character)) {
                if (islower(character)) {
                    char temp = (((character - 97)-shift)%26)+97;
                    if(temp < 97) {
                        temp += 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
                else if (isupper(character)) {
                    char temp = (((character - 65)-shift)%26)+65;
                    if(temp < 65){
                        temp += 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
            }
            else {
                fputc(character, output);
                fputc(character, stdout);
            }
        }
        printf("\n");
    }

    fclose(input);
    fclose(output);
    return 0;
}
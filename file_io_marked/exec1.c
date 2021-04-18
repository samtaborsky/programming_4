#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main(void) {
    int symbols = 0, letters_total = 0, lowerc = 0, upperc = 0, digits = 0, lines = 1, words = 0, word_cnt = 0;
    int character, last_char;
    FILE *input;

    input = fopen("input.txt", "r");

    if (input == NULL) {
        printf("Input file could not be opened, exiting...\n");
        return EXIT_FAILURE;
    }

    while ((character = fgetc(input)) != EOF) {
        symbols++;
        if (islower(character)) {
            lowerc++;
            letters_total++;
            word_cnt++;
        }
        else if (isupper(character)) {
            upperc++;
            letters_total++;
            word_cnt++;
        }
        else if (isdigit(character)) {
            digits++;
        }
        else if (character == 10) {
            lines++;
        }
        if (isspace(character) || ispunct(character)) {
            if (word_cnt == 1) {
                // this is to check for one letter words - A, a, I
                // I could include also i but let's assume that the file is gramatically correct
                fseek(input, -2L, SEEK_CUR);
                last_char = fgetc(input);
                if (last_char == 65 || last_char == 97 || last_char == 73) {
                    words++;
                }
                fseek(input, 1L, SEEK_CUR);
            }
            if (word_cnt >= 2) {
                words++;
            }
            word_cnt = 0;
        }
    }

    printf("---------- Statistics of the text file ----------\n");
    printf("- Number of symbols: %d\n"
           "- Number of lowercase letters: %d\n"
           "- Number of uppercase letters: %d\n"
           "- Number of letters in total: %d\n"
           "- Number of digits: %d\n"
           "- Number of lines: %d\n"
           "- Number of words: %d\n", symbols, lowerc, upperc, letters_total, digits, lines, words);
    printf("-------------------------------------------------\n");

    fclose(input);
    return 0;
}
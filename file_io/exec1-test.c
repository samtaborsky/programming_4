#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    long count;
    int character;
    FILE *input, *output;

    input = fopen("input_text.txt", "r");
    output = fopen("output_text.txt", "w");

    if (input == NULL) {
        printf("Input file could not be opened, exiting...\n");
        return 1;
    }
    if (output == NULL) {
        printf("Output file could not be opened, exiting...\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    count = ftell(input);
    fseek(input, -1L, SEEK_END);

    while (count > 0) {
        character = fgetc(input);
        if (character == 13) {}
        else {fputc(character, output);}
        fseek(input, -2L, SEEK_CUR);
        count--;
    }

    fclose(input);
    fclose(output);
    return 0;
}

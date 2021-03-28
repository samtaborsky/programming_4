#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
    char character = 0;
    int state = 0;
    FILE *input, *output;

    input = fopen("webpage2.html", "r");
    output = fopen("output_text.txt", "w");

    if (input == NULL) {
        printf("Input file could not be opened, exiting...\n");
        return 1;
    }
    if (output == NULL) {
        printf("Output file could not be opened, exiting...\n");
        return 1;
    }

    while (character != EOF) {
        character = fgetc(input);
        if (character == 60) {state = 0;}
        else if (character == 62) {state = 1;}
        if (state == 1) {
            if (character == 62) {}
            else {fputc(character, output);}
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
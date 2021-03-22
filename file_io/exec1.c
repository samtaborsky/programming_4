#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

long count_chars(FILE *input)
{
    fseek(input, 0, SEEK_END);
    long size_of_file = ftell(input);
    return size_of_file;
}

int main()
{
    long count;
    char character;
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

    count = count_chars(input);
    fseek(input, -1L, SEEK_END);

    while (count > 0) {
        character = fgetc(input);
        if (character == '\n') {}
        else {fputc(character, output);}
        fseek(input, -2L, SEEK_CUR);
        count--;
    }

    fclose(input);
    fclose(output);
    return 0;
}

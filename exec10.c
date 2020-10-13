#include <stdio.h>

int main() {
    char a = 0;
    int ascii;
    printf("Enter a character: ");
    scanf("%c", &a);
    ascii = a;

    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
        printf("This character is an alphabet.\n");
    }
    else if (ascii >= 48 && ascii <= 57) {
        printf("This character is a number.\n");
    }
    else {
        printf("This character is a special symbol.\n");
    }

    return 0;
}
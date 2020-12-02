#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// I have done this a bit differently than you probably expected and I realized it after I had written
// most of the code, but to get the behaviour you expected (at least I think so), you can go
// through all the parts 2-7 and after each part, select y, otherwise the program will terminate.
// I am sorry if this is an inconvenience, but I hope that the comments made it at least a little bit
// easier to understand. Some solutions are far from perfect, but I did not want to implement stuff
// in a way we have not yet studied, because I want to be sure I am implementing it correctly, even if
// not in the most efficient way.

int main() {
    char cont;
    // generate the array
    int count = 0;
    int count_of_items = 0;

    do {
        printf("How many integers do you want to generate? (1000-20 000): ");
        scanf("%d", &count);
    }
    while (count < 1000 || count > 20000);

    int numbers[count];

    srand(time(NULL) * time(NULL));
    for (int i = 0; i < count; i++) {
        numbers[i] = rand() % 10001 - 5000;
    }

    do { // loop which checks if user wants to see another part of the program
        int choice;
        do { // choose which part of the homework to display
            printf("Which part of the homework would you like to see?(2-7): ");
            scanf("%d", &choice);
        }
        while (choice < 2 || choice > 7);

        if (choice == 2) { // display all the items in the array
            printf("\n");
            for (int i = 0; i < count; i++) {
                printf("%d ", numbers[i]);
            }
            printf("\n");
        }

        else if (choice == 3) { // display all items which have 3 digits
            printf("\n");
            for (int i = 0; i < count; i++) {
                if (numbers[i] >= 100 && numbers[i] <= 999) {
                    printf("%d ", numbers[i]);
                }
            }
            printf("\n");
        }

        else if (choice == 4) { // display the number of positive, negative and neutral items
            int positive = 0;
            int negative = 0;
            int neutral = 0;

            for (int i = 0; i < count; i++) {
                if (numbers[i] > 0) {
                    positive++;
                }
                else if (numbers[i] < 0) {
                    negative++;
                }
                else if (numbers[i] == 0) {
                    neutral++;
                }
            }
            printf("Positive numbers: %d\n"
                   "Negative numbers: %d\n"
                   "Neutral numbers: %d\n", positive, negative, neutral);
        }

        else if (choice == 5) { // look for a number, display its count and positions in the array
            int number_to_check = 0;
            int count_of_numbers = 0;
            int pos_count = 0;
            int positions[count];
            printf("Enter the number to look for: ");
            scanf("%d", &number_to_check);
            for (int i = 0; i < count; i++) {
                if (numbers[i] == number_to_check) {
                    count_of_numbers++;
                    positions[pos_count] = i;
                    pos_count++;
                }
            }
            printf("Count: %d\n"
                   "Positions: ", count_of_numbers);
            for (int i = 0; i < pos_count; i++) {
                printf("%d ", positions[i]);
            }
            printf("\n");
        }

        else if (choice == 6) { // reverse the array
            int reverse_numbers[count];
            int count_temp = count - 1;
            for (int i = 0; i < count; i++) {
                reverse_numbers[count_temp] = numbers[i];
                count_temp--;
                count_of_items++;
            }
            printf("\nThe new array: \n");
            for (int i = 0; i < count; i++) {
                printf("%d ", reverse_numbers[i]);
            }
            printf("\n");
        }

        else if (choice == 7) { // reverse the array and check for matching numbers

            // I have one question, whenever there is a matching number in the arrays
            // it will be displayed 2 times, on both "halves" of the array (e.g. number
            // 1234 is the same on positions 4257 and 15742. Is this the expected
            // behaviour or should I check only one half of the arrays?

            int reverse_numbers[count];
            int count_temp = count - 1;
            for (int i = 0; i < count; i++) {
                reverse_numbers[count_temp] = numbers[i];
                count_temp--;
                count_of_items++;
            }
            printf("Matching numbers: format - number(position)\n");
            for (int i = 0; i < count; i++) {
                if (numbers[i] == reverse_numbers[i]) {
                    printf("%d(%d) ", numbers[i], i);
                }
            }
            printf("\n");
        }

        printf("Do you want to see another part of the homework? (y/n): ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        cont = getchar();
    }
    while (cont == 'y' || cont == 'Y');

    return 0;
}

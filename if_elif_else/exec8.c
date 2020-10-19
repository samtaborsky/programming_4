#include <stdio.h>

int main() {
    int roll = 0, chem = 0, phys = 0, cs = 0;
    double average = 0;

    printf("Input the Roll Number of the student: ");
    scanf("%d", &roll);
    printf("Input the marks of Physics, Chemistry and Computer Studies: ");
    scanf("%d %d %d", &phys, &chem, &cs);

    printf("Roll No: %d\n"
           "Marks in Physics: %d\n"
           "Marks in Chemistry: %d\n"
           "Marks in CS: %d\n"
           "Total marks: %d\n" , roll, phys, chem, cs, phys + chem + cs);

    average = ((double)phys + chem + cs) / 3;
    if (average >= 75) {
        printf("Percentage: %.2lf\n"
               "Division: First\n", average);
    }
    else if (average >= 50 && average < 75) {
        printf("Percentage: %.2lf\n"
               "Division: Second\n", average);
    }
    else if (average >= 33 && average < 50) {
        printf("Percentage: %.2lf\n"
               "Division: Pass\n", average);
    }
    else {
        printf("Percentage: %.2lf\n"
               "Division: Fail\n", average);
    }

    return 0;
}

#include <stdio.h>

int main() {
    int x = 0, y = 0;
    printf("Enter the coordinates: ");
    scanf("%d %d", &x, &y);

    if (x*y == 0) {
        printf("The point does not belong in any quadrant\n");
    }
    else if (x > 0 && y > 0) {
        printf("The point lies in the FIRST quadrant\n");
    }
    else if (x < 0 && y > 0) {
        printf("The point lies in the SECOND quadrant\n");
    }
    else if (x < 0 && y < 0) {
        printf("The point lies in the THIRD quadrant\n");
    }
    else {
        printf("The point lies in the FOURTH quadrant\n");
    }

    return 0;
}
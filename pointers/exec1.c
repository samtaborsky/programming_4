#include <stdio.h>
#include <stdlib.h>

int k,l;
double y;
int array2[10];

int main()
{
    int a,b,c;
    double x;
    int array1[10];

    printf("k - address: %p size: %d B\n", &k, (int)sizeof(k));
    printf("l - address: %p size: %d B\n", &l, (int)sizeof(l));
    printf("y - address: %p size: %d B\n", &y, (int)sizeof(y));
    printf("array2 - size: %d B\n"
           "first el. - address: %p size: %d B\n"
           "last el. - address: %p size: %d B\n\n",
           (int)sizeof(array2), &array2[0], (int)sizeof(array2[0]), &array2[10], (int)sizeof(array2[10]));

    printf("a - address: %p size: %d B\n", &a, (int)sizeof(a));
    printf("b - address: %p size: %d B\n", &b, (int)sizeof(b));
    printf("c - address: %p size: %d B\n", &c, (int)sizeof(c));
    printf("x - address: %p size: %d B\n", &x, (int)sizeof(x));
    printf("array1 - size: %d b\n"
           "first el. - address: %p size: %d B\n"
           "last el. - address: %p size: %d B\n\n",
           (int)sizeof(array1), &array1[0], (int)sizeof(array1[0]), &array1[10], (int)sizeof(array1[10]));

    // variable a - hexadecimal value and formal pointer representation
    printf("%x   %p\n", &a, &a);

    return 0;
}
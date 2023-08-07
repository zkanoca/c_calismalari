#include <stdio.h>
#include <string.h>

void main()
{

    int x[6] = {10, 21, 23, 51, 91, 33};
    int i = 0;

    int *px;

    px = &x[3]; // px = &x[0]; ile ayni

    printf("*px = %d \n\n", *px);

    printf("*(px+1) = %d \n\n", *(px + 1));

    printf("*(px+5) = %d \n\n", *(px - 2));

    printf("*(px+6) = %d \n\n", *(px + 6));

    printf("x[6] = %d \n\n", x[9]);
}

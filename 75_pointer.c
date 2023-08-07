#include <stdio.h>
#include <string.h>

void main()
{

    int x[6];

    int i;

    for (i = 0; i < 6; i++)
    {
        printf("&x[%d] degeri: %p\n\n", i, &x[i]);
    }

    printf("x dizisinin adresi: %p", x);
}
// X D Bin
// 0 0 0000
// 1 1 0001
// 2 2 0010
// 3 3 0011
// 4 4 0100
// 5 5
// 6 6
// 7 7
// 8 8
// 9 9
// A 10 
// B 11
// C 12
// D 13
// E 14 
// F 15
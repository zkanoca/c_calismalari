#include <stdio.h>

// 3 boyutlu matris ornegi

int main()
{

    int matris1[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                            {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}};

    printf("%d", matris1[1][2][3]); //24
    printf("\n%d", matris1[0][1][2]); //7

    return 0;
}
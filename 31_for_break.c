#include <stdio.h>

// for dongusu ile 1-n arası sayıların toplamını hesaplama
int main()
{

    int i, j;

    for (i = 1; i <= 10; i++)
    {
        if (i == 3)
            continue;

        for (j = 1; j <= i; j++)
        {
            if (j > 5)
                break;

            printf("*");
        }

        printf("\n");
    }

    return 0;
}
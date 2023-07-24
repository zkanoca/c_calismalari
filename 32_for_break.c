#include <stdio.h>

// for dongusu ile 1-n arası sayıları ekrana yazdırma
int main()
{

    int i, j;

    for (i = 1; i <= 10; i++)
    {
        if (i == 7)
            continue;

        printf("%d\t", i);
    }

    printf("\n");

    for (i = 1; i <= 10; i++)
    {
        if (i == 7)
            break;

        printf("%d\t", i);
    }

    return 0;
}
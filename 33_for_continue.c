#include <stdio.h>

// for dongusu ile 1-n arası sayıları ekrana yazdırma
int main()
{

    int i, j;

    printf("Tek sayilar:\t");
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            continue;

        printf("%d\t", i);
    }


    printf("\nCift sayilar:\t");
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 == 1)
            continue;

        printf("%d\t", i);
    }
    return 0;
}
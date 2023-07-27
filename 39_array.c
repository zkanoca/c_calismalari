#include <stdio.h>

//bubble sort ornek
void main()
{

    int i, j, k, gecici, diziUzunluk = 5;
    int sayilar[diziUzunluk];

    for (i = 0; i < diziUzunluk; i++)
    {
        printf("\n%d. Sayi: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    for (i = 0; i < diziUzunluk - 1; i++)
    {
        for (j = 0; j < diziUzunluk - 1 - i; j++)
        {
            if (sayilar[j] > sayilar[j + 1])
            {
                // takaslama islemi
                gecici = sayilar[j];
                sayilar[j] = sayilar[j + 1];
                sayilar[j + 1] = gecici;
            }

            printf("\n");
            for (k = 0; k < diziUzunluk; k++)
            {
                printf("%d\t", sayilar[k]);
            }
            printf("\n");
        }
            printf("\n------------------------------------------------------------");

    }
}
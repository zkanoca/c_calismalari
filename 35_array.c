#include <stdio.h>

void main()
{
     //              0   1    2
    int sayilar[] = {10, 20, 22};
    int i, diziUzunluk;

    //dizinin kaç elemanlı olduğunu hesapla
    diziUzunluk = sizeof(sayilar) / sizeof(sayilar[0]);

    for (i = 0; i < diziUzunluk; i++)
    {
        sayilar[i] *= sayilar[i];

        printf("\n%d. sayinin karesi: %d", i + 1, sayilar[i]);
    }
}
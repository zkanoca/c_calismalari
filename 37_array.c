#include <stdio.h>

// kullanicidan gelen sayıların en büyüğünü bulan program.

void main()
{
    int diziUzunluk = 5;
    int sayilar[diziUzunluk];
    int i, enBuyuk, enKucuk;

    for (i = 0; i < diziUzunluk; i++)
    {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    // sayilar[] = {159, 258, 326, 15, 64};
    enBuyuk = sayilar[0];
    enKucuk = sayilar[0];

    for (i = 0; i < diziUzunluk; i++)
    {
        //en buyuk degeri kiyasla
        if (enBuyuk < sayilar[i])
        {
            enBuyuk = sayilar[i];
        }
        //en kucuk degeri kiyasla
        if (enKucuk > sayilar[i])
        {
            enKucuk = sayilar[i];
        }
    }

    printf("\nGirilen sayilar icinde en buyuk olani:\t%d", enBuyuk);
    printf("\nGirilen sayilar icinde en kucuk olani:\t%d", enKucuk);
}
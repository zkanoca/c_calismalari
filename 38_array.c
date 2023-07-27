#include <stdio.h>

// kullanicidan gelen sayıların toplamini bulan program.

void main()
{
    int diziUzunluk = 5;
    int sayilar[diziUzunluk];
    int i, toplam = 0;

    //diziye deger girisi yapilir.
    for (i = 0; i < diziUzunluk; i++)
    {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    //toplama islemi
    for (i = 0; i < diziUzunluk; i++)
    {
        toplam += sayilar[i];
    }

    printf("\nDizi elemanlarinin toplam degeri:\t%d", toplam);
 }
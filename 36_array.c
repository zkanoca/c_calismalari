#include <stdio.h>

void main()
{
    int diziUzunluk = 5;
    int sayilar[diziUzunluk];
    int i;

    // dizinin kaç elemanlı olduğunu hesapla
    // diziUzunluk = sizeof(sayilar) / sizeof(sayilar[0]);

    for (i = 0; i < diziUzunluk; i++)
    {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    for (i = 0; i < diziUzunluk; i++)
    {
        printf("\n%d. sayi:\t%d", i + 1, sayilar[i]);
    }
}
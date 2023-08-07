#include <stdio.h>
#include <string.h>

void main()
{

    system("cls");

    int sayi = 5534;
    int *psayi;

    psayi = &sayi;

    sayi = 2023;

    // printf("\n\nsayi: %d\n\n", sayi);

    // printf("\n\n*psayi: %d\n\n", *psayi);

    // printf("\n\n\n***********************************\n\n\n");

    // *psayi = 5789;

    // printf("\n\n*psayi: %d\n\n", *psayi);

    // printf("\n\nsayi: %d\n\n", sayi);

    printf("\n\n\n***********************************\n\n\n");

    *psayi = 0x000000000062FE18;

    printf("\n\n*psayi: %d\n\n", *psayi);

    printf("\n\nsayi: %d\n\n", sayi);

} 
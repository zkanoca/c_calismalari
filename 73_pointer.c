#include <stdio.h>
#include <string.h>

void main()
{

    system("cls");

    int sayi1, sayi2;
    int *psayi;

    sayi1 = 100;

    sayi2 = -34;

    printf("\n\n\n***********************************\n\n\n");

    psayi = &sayi1;
    printf("\n\n*psayi: %d\n\n", *psayi);
    printf("\n\n sayi1 adresi: %x\n\n", psayi);
    printf("\n\n sayi1 adresi: %x\n\n", &sayi1);

    psayi = &sayi2;
    printf("\n\n*psayi: %d\n\n", *psayi);
    printf("\n\n sayi2 adresi: %x\n\n", psayi);
    printf("\n\n sayi2 adresi: %x\n\n", &sayi2);
}
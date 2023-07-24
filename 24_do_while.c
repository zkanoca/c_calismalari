#include <stdio.h>
/*
    Do - While dongusu kullanarak tek veya cift sayilari yazdiran program.
*/
int main()
{

    int sinirDeger;
    int sayi = 1; // cift sayilar icin sayi = 0;

    printf("Sinir Degeri Giriniz: ");
    scanf("%d", &sinirDeger);

    // while (sayi <= sinirDeger)
    do
    {

        printf("%d\t", sayi);

        sayi += 2;
    } while (sayi <= sinirDeger);

    return 0;
}
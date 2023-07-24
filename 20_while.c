#include <stdio.h>
/*
    While dongusu kullanarak tek veya cift sayilari yazdiran program.
*/
int main()
{

    int sinirDeger;
    int sayi = 1; //cift sayilar icin sayi = 0;

    printf("Sinir Degeri Giriniz: ");
    scanf("%d", &sinirDeger);

    while (sayi <= sinirDeger)
    {

        printf("%d\t", sayi);

        sayi += 2;
    }

    return 0;
}
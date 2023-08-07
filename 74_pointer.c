#include <stdio.h>
#include <string.h>

void main()
{

    system("cls");

    int sayi;
    int *psayi;

    sayi = 100;

    *psayi = &sayi; // hatalı bir işlem

    psayi = &sayi; // bu tamam

    *psayi = sayi; // bu da tamam

    printf("%x", sayi);



    int *p = &sayi; //bunda sorun yok.
    int* p = &sayi; //bunda sorun yok.

    //yukarıdaki satırın eşiti
    int *p;
    p = &sayi;

}
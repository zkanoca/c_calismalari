#include <stdio.h>
#include <string.h>

void main(){

    system("cls");

    int sayi = 5534;

    int* ptr = &sayi;

    // sadece p1 pointer olarak tanımmlanır.
    int *p1, toplam;

    //pointer olarak tanimla
    int * p2;

    //eger tum degiskenler pointer olacaksa
    int* p3, p4, p5;



    printf("sayi: %d\n", sayi);
    
    printf("sayi degiskeni adresi: %p\n", &sayi);
    
    printf("sayi degiskeni adresi: %x\n", &sayi);
    
    
}
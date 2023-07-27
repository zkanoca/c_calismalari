#include <stdio.h>


void main() {

    char ad[40];
    char soyad[40];


    printf("Adiniz: ");
    scanf("%s", ad);

    printf("\nSoyadiniz:");
    scanf("%s", soyad);

    printf("Merhaba %s %s!\n", ad, soyad);

    printf("\n%c", ad[0]);

    ad[4] = 'N';

    
    printf("\nMerhaba %s %s!\n", ad, soyad);

}
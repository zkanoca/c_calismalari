#include <stdio.h>


void main() {

    char ad[40];
    char soyad[40];


    printf("Adiniz: ");
    // scanf("%s", ad);
    fgets(ad, sizeof(ad), stdin);

    printf("\nSoyadiniz:");
    // scanf("%s", soyad);

    fgets(soyad, sizeof(soyad), stdin);

    printf("Merhaba %s %s!\n", ad, soyad);

    printf("\n%c", ad[0]);

    ad[4] = 'N';

    
    printf("\nTekrar merhaba %s %s!\n", ad, soyad);

}
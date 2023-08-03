#include <stdio.h>

void main()
{

    char isim[20];

  
   
    printf("Adinizi ve soyadinizi yaziniz: ");
    // scanf("%s", isim); //Birden fazla kelime girişi kabul etmiyor.
    scanf("%[^\n]s", isim); //karakter dizisi \n olana kadar kabul eder.

    printf("\nMerhaba %s", isim);
}
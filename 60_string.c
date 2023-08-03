#include <stdio.h>
#include <string.h>

void main()
{
    char isim[20];

    int isimUzunluk = 0;

    printf("Adinizi yazin: ");

    gets(isim); //scanf("%[^\n]s", isim);

    isimUzunluk = strlen(isim); //string length

    printf("\nAdiniz %d harfli\n", isimUzunluk); 


}
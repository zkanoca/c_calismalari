#include <stdio.h>

void main()
{
    char isim[20];


    printf("Adinizi yazin: ");

    gets(isim); //scanf("%[^\n]s", isim);

    printf("\nMerhaba %s\n", isim);
}
#include <stdio.h>
#include <string.h>

void main()
{
    char isim[20];

    printf("Adinizi yaziniz: ");

    gets(isim);

    printf("Adiniz:\t\t%s\n", isim);
    printf("Adinizin tersten yazilisi:\t%s\n", strrev(isim));

   
}
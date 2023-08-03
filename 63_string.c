#include <stdio.h>
#include <string.h>

void main()
{

    char secenek[5];

    printf("Dosyayi silmek istediginizden emin misini? [Evet/H]");

    gets(secenek);

    // strcmp(s1, s2) s1 ile s2 aynıysa 0, degilse 1 doner
    // if (strcmp(secenek, "Evet") == 0)
    if (strcmpi(secenek, "evet") == 0)
    // if (secenek == "Evet") //çalışmaz
    {
        printf("\nDosya silindi.");
    }
    else
    {
        printf("\nDosya silinmedi.");
    }
}
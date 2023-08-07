#include <stdio.h>
#include <string.h>

void main()
{

    int x[6], i = 0, toplam = 0;

    printf("6 adet sayı giriniz:\n");

    for (i = 0; i < 6; i++)
    {
        scanf("%d", x + i);
        toplam += *(x + i);
    }
    printf("\n\nDizi Toplami: %d\n", toplam);
}

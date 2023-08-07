#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, *p, toplam=0;

    printf("Eleman sayisini giriniz: ");
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int) * n);

    // bellekte yeterli yer yoksa
    if (p == NULL)
    {

        printf("Bellekte yeterli alan bulunmamaktadir.\n");
        exit(0);
    }

    printf("Elemanlari giriniz: ");

    for (i = 0; i < n;i++)
    {
        scanf("%d", p + i);
        toplam += *(p + i);
        printf("Girilen %d sayinin toplami: %d\n\n", i + 1, toplam);

    }

    printf("Genel Toplam: %d", toplam);

    //malloc ile ayrılan alanı serbest bırak
    free(p);
}
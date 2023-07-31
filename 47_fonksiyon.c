#include <stdio.h>

int main()
{
    int i, son, toplam;

    printf("\nBu program 1 ile girilen sayi arasindaki sayilari toplar\n ");
    printf("Son sayiyi yaziniz: ");

    scanf("%d", &son);

    for (i = 0; i <= son; i++)
    {
        toplam = toplam + i;
        printf("%d\t%d\n", i, toplam);
    }

    printf("\n%d'den %d'ye kadar sayilarin toplami %d'dir.", 1, son, toplam);

    return 0;
}

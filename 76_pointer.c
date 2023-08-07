#include <stdio.h>
#include <string.h>

void main()
{

    int x[6], i = 0, toplam = 0;

    printf("6 adet sayı giriniz:\n");
    scanf("%d%d%d%d%d%d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]);

    for(i = 0; i < 6; i++)
    {
        printf("\n\n%d\n", x[i]);

    }

}

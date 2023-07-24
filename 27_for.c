#include <stdio.h>

// while dongusu ile fibonacci serisi oluşturma
int main()
{

    int i, toplam=0, n;

    printf("n. terimi yaziniz:");
    scanf("%d", &n);

    for(i = 0; i <= n; i++)
    {
        toplam += i;
    }

    printf("\n0-%d arasindaki sayilarin toplam degeri: %d", n, toplam);
    return 0;
}
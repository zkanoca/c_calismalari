#include <stdio.h>

// for dongusu ile 1-n arası sayıların toplamını hesaplama
int main()
{

    int i, toplam=0, n;

    printf("n. terimi yaziniz:");
    scanf("%d", &n);

    // for(i = 0; i <= n; i +) // sayilar icin
    // for(i = 0; i <= n; i += 2) //cift sayilar icin
    for(i = 1; i <= n; i += 2)  //tek sayilar icin
    {
        toplam += i;
    }

    // printf("\n0-%d arasindaki sayilarin toplam degeri: %d", n, toplam);
    // printf("\n0-%d arasindaki cift sayilarin toplam degeri: %d", n, toplam);
    printf("\n0-%d arasindaki tek sayilarin toplam degeri: %d", n, toplam);
    return 0;
}
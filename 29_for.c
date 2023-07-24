#include <stdio.h>

// for dongusu ile 1-n arası sayıların toplamını hesaplama
int main()
{

    int baslangic, toplam = 0, bitis, i;

    printf("baslangic degerini yaziniz:");
    scanf("%d", &baslangic);

    printf("bitis degerini yaziniz:");
    scanf("%d", &bitis);

    for (i = baslangic; i <= bitis; i++)
    {
        toplam += i;
    }

    printf("\n[%d, %d] arasindaki tek sayilarin toplam degeri: %d",
                 baslangic, bitis, toplam);
    return 0;
}
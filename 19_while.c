#include <stdio.h>

int main(){

    int toplam = 0;
    int deger;

    while (deger != -1)
    {
        printf("\nBir sayi yaziniz: "); scanf("%d", &deger);

        if (deger != -1 )
            toplam += deger;
    }

    printf("Girilen sayilarin toplami: %d", toplam);

    return 0;
}
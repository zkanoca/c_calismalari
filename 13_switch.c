/*
    switch (sart){
        case x: 
            kodlar
            break;
        case y:
            kodlar
            break;
        default: 
            kodlar
            
    }

*/


#include <stdio.h>

int main()
{
        int sayi1, sayi2;
        int islem;
        float sonuc;

        printf("Birinci sayiyi yaziniz: ");
        scanf("%d", &sayi1);

        printf("Ikinci sayiyi yaziniz: ");
        scanf("%d", &sayi2);

        printf("Islemi belirtiniz ( +:1, -:2, *:3, /:4): ");
        scanf("%d", &islem);


        switch (islem) {
            case 4 : 
                sonuc = sayi1 / sayi2;
            break;
            case  1 :
                sonuc = sayi1 + sayi2;
            break;
            case 2 : 
                sonuc = sayi1 - sayi2;
            break;
            case  3 :
                sonuc = sayi1 * sayi2;
            break;
            
        } 

        printf("\nSonuc: %f", sonuc);
}
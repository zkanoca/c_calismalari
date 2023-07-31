#include <stdio.h>

int main()
{
    int sayi1, sayi2;
    float sonuc;

    int islem;

    printf("\nBirinci sayiyi yaziniz: ");
    scanf("%d", &sayi1);

    printf("\nIkinci sayiyi yaziniz: ");
    scanf("%d", &sayi2);

    printf("\nHangi Islem yapilacak? (1.Toplama, 2.Cikarma, 3.Carpma, 4.Bolme): ");
    scanf("%d", &islem);

    switch (islem)
    {
    case 1:
        // sonuc = sayi1 + sayi2;
        // printf("\n%d + %d = %f", sayi1, sayi2, sonuc);
        topla(sayi1, sayi2);
        break;
    case 2:
        // sonuc = sayi1 - sayi2;
        // printf("\n%d - %d = %f", sayi1, sayi2, sonuc);
        cikar(sayi1, sayi2);
        break;
    case 3:
        // sonuc = sayi1 * sayi2;
        // printf("\n%d * %d = %f", sayi1, sayi2, sonuc);
        carp(sayi1, sayi2);
        break;
    case 4:
        // sonuc = sayi1 / sayi2;
        // printf("\n%d / %d = %f", sayi1, sayi2, sonuc);
        bol(sayi1, sayi2);
        break;
    default:
        sonuc = 0;
        printf("\nGecersiz Islem");
    }

    return 0;
}

void topla(int a, int b)
{
    int s = a + b;
    printf("\n%d + %d = %d", a, b, s);
}

void cikar(int a, int b)
{
    int s = a - b;
    printf("\n%d - %d = %d", a, b, s);
}

void carp(int a, int b)
{
    int s = a * b;
    printf("\n%d * %d = %d", a, b, s);
}

void bol(int a, int b)
{
    float s = a / b;
    printf("\n%d / %d = %f", a, b, s);
}
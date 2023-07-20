#include <stdio.h>

int main()
{

    // ax^2 + bx + c = 0 şeklindeki denklemin reel
    // köklerinin olup olmadığının araştırılması.

    float a, b, c, delta;

    printf("ax^2 + bx + c = 0 seklindeki denklem icin sirasiyla a, b ve c degerlerini giriniz: ");

    scanf("%f%f%f", &a, &b, &c);

    delta = (b * b) - 4 * a * c;

    if (delta < 0 )
    {
        printf("\nReel kok yoktur.");
    } 
    else if (delta == 0)
    {
        printf("\nBir reel kok vardir.");
    }
    else 
    {
        printf("\nIki adet reel koku vardir");
    }

    return 0;
}
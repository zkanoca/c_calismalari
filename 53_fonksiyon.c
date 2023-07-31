#include <stdio.h>
#include <math.h>

int main()
{

    float sayi = 22.456;
    float negatifSayi = -22.5;

    // ceil
    printf("\n%.3f sayisinin yukari yuvarlanmis degeri: %.3f", sayi, ceil(sayi));

    // floor
    printf("\n%.3f sayisinin asagi yuvarlanmis degeri: %.3f", sayi, floor(sayi));

    // sqrt --> karekok
    printf("\n%.3f sayisinin karekok degeri: %.3f", sayi, sqrt(sayi));

    // pow --> kuvvet fonksiyonu
    printf("\n%.3f sayisinin kupu: %.3f", sayi, pow(sayi, 3));

    // pow --> kuvvet fonksiyonu
    printf("\n%.3f sayisinin besinci kuvveti: %.3f", sayi, pow(sayi, 5));

    // abs --> mutlat deger fonksiyonu
    printf("\n%f sayisinin mutlak degeri: %f", negatifSayi, abs(negatifSayi));


    return 0;
}

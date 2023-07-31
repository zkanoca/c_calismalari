#include <stdio.h>

int main()
{

    int x = 2, y = 4;

    int toplam = topla(x, y);

    int carpim = carp(x, y);

    int fark = cikar(x, y);

    // float bolum = bolme(x, y);

    printf("Toplam: %d\nFark: %d\nCarpim: %d\n", toplam, fark, carpim);

    return 0;
}

int topla(int a, int b)
{
    return a + b;
}

int cikar(int a, int b)
{
    return a - b;
}

int carp(int a, int b)
{
    return a * b;
}

// float bolme(int a, int b)
// {
//     float s = a / b;
//     return s;
// }
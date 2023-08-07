#include <stdio.h>
#include <string.h>

//call by value
void takasla(int x, int y)
{
    int gecici = x;

    x = y;

    y = gecici;
}

//call by reference
void takaslap(int* x, int* y)
{
    int gecici = *x;
    *x = *y;
    *y = gecici;
}

void main()
{

    int a = 10, b = 34;

    printf("\nbaslangictaki a ve b degerleri\n");
    printf("a: %d\n\nb: %d", a, b);

    takasla(a, b);

    printf("\ntakasla fonksiyonu sonucu\n");
    printf("a: %d\n\nb: %d\n\n", a, b);

    takaslap(&a, &b);

    printf("\ntakaslap fonksiyonu sonucu\n");
    printf("a: %d\n\nb: %d", a, b);
}

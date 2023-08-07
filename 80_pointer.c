#include <stdio.h>

void arttir(int* ptr)
{
    //sayi degiskeni degerine +1 ekle
    (*ptr)++;
    printf("%d\n", *ptr);

    //ptr degerine 4 ekler.
     *ptr++;
    printf("%d\n", ptr);
}

void main()
{
    int *p, sayi = 10;

    p = &sayi;

    printf("%d\n", p);
    printf("%d\n", *p);

    arttir(p);

    printf("%d\n", *p);
}
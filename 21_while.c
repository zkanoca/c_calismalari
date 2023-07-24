#include <stdio.h>

// while dongusu ile fibonacci serisi oluşturma
int main()
{

    int sinirDeger, /*i = 1,*/ terim1 = 0, terim2 = 1, sonrakiTerim;

    printf("Fibonacci serisinin sinir degerini giriniz: ");
    scanf("%d", &sinirDeger);

    while (sonrakiTerim <= sinirDeger)
    {
        printf("%d\t", terim2);
        sonrakiTerim = terim1 + terim2;
        terim1 = terim2;
        terim2 = sonrakiTerim;
        
    }

    printf("\nFibonacci Serisinin %d degerine kadar olan kismi %d'dir.", sinirDeger, terim1);

    return 0;
}
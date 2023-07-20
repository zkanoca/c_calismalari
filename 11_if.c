#include <stdio.h>

int main()
{

    int say1=11, say2=12;

    if(say1==say2)
        printf("Sayilar esit.\n");
    else
        printf("Sayilar esit degil.\n");

    //Yukarıdaki ile aynı işi yapar.
    // ? : --> Ternary Operator
    say1==say2 ? printf("Sayilarimiz esit\n") : printf("Sayilar farkli.\n");

    int buyuk = say1 > say2 ? say1 : say2;

    printf("Buyuk olan sayi: %d \n", buyuk);

    return 0;
}
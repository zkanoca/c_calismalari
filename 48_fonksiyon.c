#include <stdio.h>

float kdv(float alisFiyati)
{

    if (alisFiyati < 100)
    {
        return 1.20;
    }
    else if (alisFiyati < 200)
    {
        return 1.22;
    }
    else if (alisFiyati < 400)
    {
        return 1.25;
    }
}

float kar(float alisFiyati)
{
    //%20 kar ile sat
    return 1.20 * alisFiyati;
}

int main()
{

    float alisFiyati = 100, satisFiyati;

    satisFiyati = kar(alisFiyati) * kdv(alisFiyati) ;

    printf("\n%f\n", satisFiyati);
}

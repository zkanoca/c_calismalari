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
    else
        return 1.3;
}

float kar(float alisFiyati)
{
    //%20 kar ile sat
    return 1.20 * alisFiyati;
}

float satisFiyati(float alisFiyati)
{
    return kar(alisFiyati) * kdv(alisFiyati);
}

int main()
{

    float alisFiyati = 500.00;

    printf("\n%.2f TL\n", satisFiyati(alisFiyati));
}

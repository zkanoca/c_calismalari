#include <stdio.h>

int main()
{
    float boy, agirlik, vki;

    printf("Boyunuz (cm): ");
    scanf("%f", &boy);

    printf("\nAgirliginiz (kg): ");
    scanf("%f", &agirlik);

    vki = agirlik / (boy * boy / 10000);
    
    printf("\n%f\n", vki);

    if (vki < 18.5)
        printf("Ideal kilonun altindasiniz.");
    else if (vki >= 18.5 && vki <= 24.9)
        printf("Ideal kilodasiniz.");
    else if (vki > 24.9 && vki <= 29.9)
        printf("Ideal kilonun ustundesiniz.");
    else if (vki > 29.9 && vki <= 39.9)
        printf("Obezite sorunu yasiyorsunuz.");
    else
        printf("Morbid obez durumundasiniz.");

    return 0;
}
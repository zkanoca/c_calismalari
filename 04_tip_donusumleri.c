#include <stdio.h>

int main()
{

    int buCamelCaseDegiskeni = 0;

    int BuPascalCaseDegiskeni = 0;
    int bu_snake_case_degiskeni = 0;
    //int bu-kebab-case-degiskeni = 0; //burada gecersiz

    const int SABIT_DEGER; 
    int x = 12;
    int y = 5;
    float sonuc =  (float) 5 / 3; //casting gerekiyor.

    float toplam =   x + y; //casting işlemine gerek yok.

    float carpim = x * y; //çarpım operatörü : 60.000000
    
    int kalan = x % y; //kalan operatörü : 2

    printf("x = %d\n", x); //12
    
    x = x + 1; //13 

    printf("x = %d\n", x); //13
     
    printf("x = %d\n", x++); //ekrana 13 yazdı ve 14 oldu

    printf("x = %d\n", ++x); //15 oldu ve ekrana 15 yazdı
     
    printf("x = %d\n", x--); //ekrana 15 yazdı ve 14 oldu

    printf("x = %d\n", --x); //13 oldu ve ekrana 13 yazdı
     
    printf("Sonuç: %6.4f", sonuc);

    return 0;
}
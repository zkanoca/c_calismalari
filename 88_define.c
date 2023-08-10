#include <stdio.h>

//Normal tansiyon degerleri 12/8 olarak kabul edilir.
#define BUYUK_TANSIYON 12
#define KUCUK_TANSIYON 8

enum durumlar
{
    DUSUK_DUSUK = 0,
    DUSUK_NORMAL = 4,
    DUSUK_YUKSEK = 8,
    NORMAL_DUSUK = 1,
    NORMAL_NORMAL = 5,
    NORMAL_YUKSEK = 9,
    YUSEK_DUSUK = 2,
    YUSEK_NORMAL = 6,
    YUSEK_YUKSEK = 10,
};

void main()
{


    float bt = 15, kt = 6;
    int durum = 0;

    char sonuc[11][64] = {
        "Ikisi de dusuk",             // 0
        "buyuk dusuk",                // 1
        "Kucuk yuksek, buyuk  dusuk", // 2
        "",                           // 3
        "Kucuk dusuk",                // 4
        "Tansiyon degerleriniz iyi",  // 5
        "Buyuk yuksek",               // 6
        "",                           // 7
        "Kucuk dusuk, buyuk yuksek",  // 8
        "Kucuk yuksek",               // 9
        "Ikisi de yuksek",            // 10
    };

    if (bt < BUYUK_TANSIYON)
        durum = 0;
    else if (bt == BUYUK_TANSIYON)
        durum = 1;
    else
        durum = 2;

    if (kt < KUCUK_TANSIYON)
        durum += 0;
    else if (kt == KUCUK_TANSIYON)
        durum += 4;
    else
        durum += 8;

    printf("\nTansiyon durumu: %s", sonuc[durum]);
}
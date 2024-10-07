#include <stdio.h>
#include <string.h>

struct ogrenci {
    int numara;
    char ad[30];
    char bolum[40];
    int sinif;
};

// typedef struct ogrenci {
//     int numara;
//     char ad[30];
//     char bolum[40];
//     int sinif;
// } Ogrenci;


int main()
{
    struct ogrenci ogr1;
    struct ogrenci *p;
    
    p = &ogr1;
    
    printf("Ogrenci Numarasi: ");
    scanf("%d", &p->numara);
    printf("Ogrenci Adi: ");
    scanf("%s", p->ad);
    printf("Bolum Adi: ");
    scanf("%s", p->bolum);
    printf("Sinif: ");
    scanf("%d", &p->sinif);
    
    
    //Ogrenci bilgilerini ekrana yazdir
    printf("\nOgrenci Bilgiler (Pointer)\n");
    printf("Ogrenci Numarasi\tOgrenci Adi\tBolum Adi\tSinif\n");
    printf("%d\t\t%-30s%-40s\t%d\n", p->numara, p->ad, p->bolum, p->sinif);    
    
    printf("\nOgrenci Bilgiler (Dogrudan)\n");
    printf("Ogrenci Numarasi\tOgrenci Adi\tBolum Adi\tSinif\n");
    printf("%d\t\t%-30s%-40s\t%d\n", ogr1.numara, ogr1.ad, ogr1.bolum, ogr1.sinif);    
    
    return 0;
}

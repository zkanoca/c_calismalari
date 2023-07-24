#include <stdio.h>

int main()
{

    int puan;

    int aAlanlar = 0;
    int bAlanlar = 0;
    int cAlanlar = 0;
    int dAlanlar = 0;
    int fAlanlar = 0;

    printf("Harf notunu giriniz.\n ");
    printf("(Girisi sonlandirmak icin EOF karakterini giriniz. \n)");

    while ((puan = getchar()) != EOF)
    {
        switch (puan)
        {
        case 'A':
        case 'a':
            ++aAlanlar;
            break;

        case 'B':
        case 'b':
            ++bAlanlar;
            break;

        case 'C':
        case 'c':
            ++cAlanlar;
            break;

        case 'D':
        case 'd':
            ++dAlanlar;
            break;

        case 'f':
        case 'F':
            ++fAlanlar;
            break;

        default:
            printf("Hatali Giris.\n");
            printf("Yeni bir harf notu giriniz: ");
            break;
        }
    }

    printf("\nHer harf notunun toplam sayilari asagida listelenmistir:\n");
    printf("A: %d\n", aAlanlar);
    printf("B: %d\n", bAlanlar);
    printf("C: %d\n", cAlanlar);
    printf("D: %d\n", dAlanlar);
    printf("F: %d\n", fAlanlar);

    return 0;
}
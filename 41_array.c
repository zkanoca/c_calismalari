#include <stdio.h>

// iki matrisin toplamini hesaplayan program.
int main()
{

    int SATIR = 4;
    int SUTUN = 4;

    int matris1[4][4] = {{1, 2, 4, 5},
                         {2, 5, 6, 15},
                         {5, 1, 2, 22},
                         {0, 2, 1, -8}};

    int matris2[4][4] = {{11, 21, 14, 25},
                         {12, 25, 16, 5},
                         {51, 11, 21, 2},
                         {10, 22, 31, 18}};

    int toplam[4][4];
    int i, j;

    // toplama islemi
    for (i = 0; i < SATIR; i++)
    {
        for (j = 0; j < SUTUN; j++)
        {
            toplam[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
    // toplama islemi sonucunun ekrana yazdir
    for (i = 0; i < SATIR; i++)
    {
        for (j = 0; j < SUTUN; j++)
        {
            printf("%d\t", toplam[i][j]);
        }
        printf("\n");
    }

    return 0;
}
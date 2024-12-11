#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi;
    FILE *fp;
    if ((fp = fopen("dosya.txt", "r")) == NULL)
    {
        printf("Dosya acilamadi");
        exit(1);
    }

    fscanf(fp, "%d", &sayi);

    printf("Dosyadan okunan sayi: %d", sayi);

    fclose(fp);

    return 0;
}

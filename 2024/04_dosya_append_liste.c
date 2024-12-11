#include <stdio.h>
#include <stdlib.h>

int main()
{
	char isim[40];
	int puan, i, ogrenciSayisi;
	FILE *fp;


	printf("Ogrenci Sayisini giriniz:");
	scanf("%d", &ogrenciSayisi);

	fp = fopen("ogrenci_notlari.txt", "a");

	if(fp == NULL)
	{
		printf("Dosya hatasi");
		exit(1);
	}

	for(i = 0; i < ogrenciSayisi; i++)
	{
		printf("Ogrenci %d Adi: ", i+1);
		scanf("%s", isim);

		printf("Ogrenci %d Puani:", i+1);
		scanf("%d", &puan);

		fprintf(fp, "%d. Isim: %s\tPuan: %d\n", i+1, isim, puan);

	}

	fclose(fp);

	return 0;
}
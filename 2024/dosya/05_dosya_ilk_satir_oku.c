#include <stdio.h>
#include <stdlib.h>


//Bir metin dosyasindaki ilk satiri okuyan program
int main()
{
	char metin[1000];
	FILE *fp;

	fp = fopen("metin_dosyasi.txt", "r");

	if(fp == NULL)
	{
		printf("Dosya hatasi");
		exit(1);
	}

	fscanf(fp, "%[^\n]", metin);
	
	printf("Metin dosyasi icindeki ilk satir icerigi asagidadir:\n %s", metin);

	fclose(fp);

	return 0;
}

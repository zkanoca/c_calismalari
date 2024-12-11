#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sayi;
	FILE *fp;
	fp = fopen("dosya2.txt", "w");

	if(fp == NULL)
	{
		printf("Dosya acilirken hata meydana geldi.");
		exit(1);
	}

	printf("Bir sayi yaziniz: ");
	scanf("%d", &sayi);


	fprintf(fp, "%d", sayi);

	fclose(fp);

	return 0;
}
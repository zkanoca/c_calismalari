#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100       //Maksimum kelime uzunlugu
#define MAX_NUMBER_WORDS 100 //Maksimum kelime sayisi 
#define DOSYA_ADI "sozluk.txt"



void dosyayaKaydet(char *szlk[], const char *dosyaAdi)
{
	FILE *fp = fopen(dosyaAdi, "w");

	if(fp == NULL)
	{
		printf("Dosya Acilamadi!\n");
		return;
	}

	for (int i = 0; i < MAX_NUMBER_WORDS; i++)
	{
		if (szlk[i] != NULL)
		{
			fprintf(fp, "%s\n", szlk[i]);
		}
	}

	fclose(fp);
	printf("Sozluk dosyaya kaydedildi.");
}

void listele(char *szlk[])
{
	for(int i = 0; i < MAX_NUMBER_WORDS; i++)
	{
		if(szlk[i] != NULL)
		{
			printf("%d. %s\n", i+1, szlk[i]);
		}
	}
}

void dosyadanListele()
{
	FILE *fp = fopen(DOSYA_ADI, "r");

	if(fp == NULL)
	{
		printf("Dosya acilamadi!\n");
		return;
	}

	char satir[MAX_LENGTH];
	int satirNo = 0;


	while(fgets(satir, MAX_LENGTH, fp) != NULL)
	{
		printf("%d. %s\n", satirNo+1, satir);
		satirNo++;
	}

	fclose(fp);
}

void dosyadaAra(char *kelime)
{
	FILE *fp = fopen(DOSYA_ADI, "r");

	if(fp == NULL)
	{
		printf("Dosya acilamadi!\n");
		return;
	}

	char satir[MAX_LENGTH];
	int satirNo = 0;
	int bulundu = 0;


	while(fgets(satir, MAX_LENGTH, fp) != NULL)
	{
		if(strstr(satir, kelime) != NULL) {
			printf("\"%s\"  %d. satirda bulundu.\n", kelime, satirNo);
			bulundu = 1;
		}

		satirNo++;
	}

	if(!bulundu)
	{
		printf("Kelime sozlukte bulunamadi.\n");
	}

	fclose(fp);
}


//Bir metin dosyasindaki ilk satiri okuyan program
int main()
{
	char *sozluk[MAX_NUMBER_WORDS] = {NULL};
	char kelime[MAX_LENGTH];
	char c;


	while(1) {

		printf("Komut: ");
		scanf(" %c", &c);


		switch(c) {

		case 'q':
			return 0;

		case 'a':
			printf("Kelime: ");
			scanf("%s", kelime);

			for(int i=0; i < MAX_NUMBER_WORDS; i++)
			{
				if(sozluk[i]==NULL)
				{
					sozluk[i] = (char *)malloc((strlen(kelime)+1) * sizeof(char));
					strcpy(sozluk[i], kelime);
					printf("Kelime eklendi: %s\n", kelime);
					break;
				}
			}

			break;

		case 's': //Sozlugu dosyaya kaydet
			dosyayaKaydet(sozluk, DOSYA_ADI);
			break;

		case 'd': //Sozluk dokumu
			listele(sozluk);
			break;
		case 'y': //Dosyadaki kelimeleri listele
			dosyadanListele();
			break;
		case 'b':
			char aranacakKelime[MAX_LENGTH];
			printf("Aranacak kelime: ");
			scanf("%s", aranacakKelime);
			dosyadaAra(aranacakKelime);
			break;

		default:
			printf("Gecersiz Komut!\n");
			break;
		}

	}


	FILE *fp;

	return 0;
}
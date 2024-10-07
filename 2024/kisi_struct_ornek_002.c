#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSON 10

struct kisi {
	char *isim;
	int yas;
	float kilo;
};

void kisiEkle(struct kisi *kisiler, int *kisiSayisi)
{
	if(*kisiSayisi >= MAX_PERSON)
	{
		printf("Azami kisi sayisina ulasildi.\n");
		return;
	}

	char isim[50];
	int yas;
	float kilo;

	printf("Isim: ");
	scanf("%s", isim);
	printf("Yas: ");
	scanf("%d", &yas);
	printf("kilo: ");
	scanf("%f", &kilo);

	kisiler[*kisiSayisi].isim = (char*)malloc(strlen(isim)+1);
	strcpy(kisiler[*kisiSayisi].isim, isim);
	kisiler[*kisiSayisi].yas = yas;
	kisiler[*kisiSayisi].kilo = kilo;

	(*kisiSayisi)++;
	printf("Kisi eklendi.\n");
}



void kisiGuncelle(struct  kisi *kisiler, int kisiSayisi)
{
	if(kisiSayisi == 0)
	{
		printf("Liste bos.");
		return;
	}

	int index;
	printf("Guncellemek istediginiz kisinin sira numarasini yaziniz (0-%d) :", kisiSayisi-1);
	scanf("%d", &index);

	if(index < 0 || index >= kisiSayisi)
	{
		printf("Gecersiz indeks numarasi.\n");
		return;
	}

	char isim[50];
	int yas;
	float kilo;

	printf("Isim: ");
	scanf("%s", isim);
	printf("Yas: ");
	scanf("%d", &yas);
	printf("kilo: ");
	scanf("%f", &kilo);

	free(kisiler[index].isim);
	kisiler[index].isim = (char *)malloc(strlen(isim) + 1);
	strcpy(kisiler[index].isim, isim);
	kisiler[index].yas = yas;
	kisiler[index].kilo = kilo;

	printf("Kisi guncellendi.\n");
}


void kisiSil(struct kisi *kisiler, int *kisiSayisi)
{
	if(*kisiSayisi == 0)
	{
		printf("Liste bos.");
		return;
	}

	int index;
	printf("Silmek istediginiz kisinin sira numarasini yaziniz (0-%d) :", *kisiSayisi-1);
	scanf("%d", &index);

	if(index < 0 || index >= *kisiSayisi)
	{
		printf("Gecersiz indeks numarasi.\n");
		return;
	}

	free(kisiler[index].isim);

	for(int i = index; i < *kisiSayisi-1; i++)
	{
		kisiler[i] = kisiler[i+1];
	}

	(*kisiSayisi)--;
	printf("Kisi silindi.\n");
}

void kisileriListele(struct kisi *kisiler, int kisiSayisi)
{
	if (kisiSayisi == 0)
	{
		printf("Liste bos.\n");
		return;
	}

	printf("##\tIsim\tYas\tKilo\n");
	for(int i = 0; i < kisiSayisi; i++)
	{
		printf("%d\t%s\t%d\t%.1f\n", i, kisiler[i].isim, kisiler[i].yas, kisiler[i].kilo);
	}
}

void kiloyaGoreSirala(struct kisi *kisiler, int kisiSayisi)
{
	for (int i = 0; i < kisiSayisi - 1; i++)
	{
		for(int j=0; j < kisiSayisi-1-i; j++)
		{
			if(kisiler[j].kilo > kisiler[j+1].kilo)
			{
				struct kisi geciciKisi = kisiler[j];
				kisiler[j] = kisiler[j+1];
				kisiler[j+1] = geciciKisi;
			}
		}
	}
}


void yasaGoreSirala(struct kisi *kisiler, int kisiSayisi)
{
	for (int i = 0; i < kisiSayisi - 1; i++)
	{
		for(int j=0; j < kisiSayisi-1-i; j++)
		{
			if( kisiler[j].yas > kisiler[j+1].yas)
			{
				struct kisi geciciKisi = kisiler[j];
				kisiler[j] = kisiler[j+1];
				kisiler[j+1] = geciciKisi;
			}
		}
	}
}


void ismeGoreSirala(struct kisi *kisiler, int kisiSayisi)
{
	for (int i = 0; i < kisiSayisi - 1; i++)
	{
		for(int j=0; j < kisiSayisi-1-i; j++)
		{
			if(strcmp(kisiler[j].isim, kisiler[j+1].isim) > 0)
			{
				struct kisi geciciKisi = kisiler[j];
				kisiler[j] = kisiler[j+1];
				kisiler[j+1] = geciciKisi;
			}
		}
	}
}

int main()
{

	struct kisi kisiler[MAX_PERSON];
	int kisiSayisi = 0;
	int secim;

	do {
		printf("\nMenu\n");
		printf("1. Kisi Ekle\n");
		printf("2. Kisi Guncelle\n");
		printf("3. Kisi Sil\n");
		printf("4. Kisileri Listele\n");
		printf("5. Ada Gore Sirala\n");
		printf("6. Yasa Gore Sirala\n");
		printf("7. Kiloya Gore Sirala\n");
		printf("0. Cikis\n");

		printf("Seciminiz: ");
		scanf("%d", &secim);


		switch(secim)
		{
		case 0: //Cikis
			printf("Hoscakalin...");
			break;

		case 1: //Kisi Ekle
			kisiEkle(kisiler, &kisiSayisi);
			break;
		case 2: //Kisi Guncelle
			kisiGuncelle(kisiler, kisiSayisi);
			break;
		case 3: //Kisi Sil
			kisileriListele(kisiler, kisiSayisi);
			kisiSil(kisiler, &kisiSayisi);
			break;
		case 4: //Kisileri Listele
			kisileriListele(kisiler, kisiSayisi);
			break;
		case 5: //Ada gore sirala
			ismeGoreSirala(kisiler, kisiSayisi);
			kisileriListele(kisiler, kisiSayisi);
			break;
		case 6: //Yasa gore sirala
			yasaGoreSirala(kisiler, kisiSayisi);
			kisileriListele(kisiler, kisiSayisi);
			break;
		case 7: //Kiloya gore sirala
			kiloyaGoreSirala(kisiler, kisiSayisi);
			kisileriListele(kisiler, kisiSayisi);
			break;
		default:
			printf("Gecersiz secim, tekrar deneyiniz.\n");
		}

	} while(secim != 0);

	return 0;
}

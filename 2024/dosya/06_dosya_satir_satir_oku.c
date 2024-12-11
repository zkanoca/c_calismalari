#include <stdio.h>
#include <stdlib.h>


//Bir metin dosyasindaki ilk satiri okuyan program
int main()
{
	char dosyaAdi[100];
	FILE *fp;
    char satir[10];
    int satirNo = 1;
    
    printf("Dosya adini yaziniz:");
    scanf("%s", dosyaAdi);

	fp = fopen(dosyaAdi, "r");

	if(fp == NULL)
	{
		printf("Dosya hatasi");
		exit(1);
	} 
	
    printf("Dosya Icerigi:\n");
    
    
    while( fgets(satir, sizeof(satir), fp) != NULL)
    {
        printf("%d: %s", satirNo, satir);
        satirNo++;
    }
	

	fclose(fp);

	return 0;
}

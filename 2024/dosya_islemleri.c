#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yeni_dosya_olustur(const char *dosya_adi);
void dosyaya_yaz(const char *dosya_adi, const char *bilgi);
void dosya_oku(const char *dosya_adi);
void dosya_sil(const char *dosya_adi);
void kelime_ara(const char *dosya_adi, const char *kelime);
void kelime_degistir(const char *dosya_adi, const char *eski_kelime, const char *yeni_kelime);
void kelime_sil(const char *dosya_adi, const char *kelime);

int main() {
    char komut, dosya_adi[100], bilgi[256], kelime[100], yeni_kelime[100];

    while (1) {
        printf("\nKomut girin: ");
        scanf(" %c", &komut);
        
        switch (komut) {
            case 'n':
                printf("Yeni dosya adı: ");
                scanf("%s", dosya_adi);
                yeni_dosya_olustur(dosya_adi);
                break;
            case 'a':
                printf("Dosya adı: ");
                scanf("%s", dosya_adi);
                printf("Eklenecek bilgi: ");
                scanf(" %[^\n]s", bilgi);
                dosyaya_yaz(dosya_adi, bilgi);
                break;
            case 'p':
                printf("Dosya adı: ");
                scanf("%s", dosya_adi);
                dosya_oku(dosya_adi);
                break;
            case 'd':
                printf("Silinecek dosya adı: ");
                scanf("%s", dosya_adi);
                dosya_sil(dosya_adi);
                break;
            case 'f':
                printf("Dosya adı: ");
                scanf("%s", dosya_adi);
                printf("Aranacak kelime: ");
                scanf("%s", kelime);
                kelime_ara(dosya_adi, kelime);
                break;
            case 'r':
                printf("Dosya adı: ");
                scanf("%s", dosya_adi);
                printf("Değiştirilecek kelime: ");
                scanf("%s", kelime);
                printf("Yeni kelime: ");
                scanf("%s", yeni_kelime);
                kelime_degistir(dosya_adi, kelime, yeni_kelime);
                break;
            case 'x':
                printf("Dosya adı: ");
                scanf("%s", dosya_adi);
                printf("Silinecek kelime: ");
                scanf("%s", kelime);
                kelime_sil(dosya_adi, kelime);
                break;
            case 'q':
                printf("Çıkılıyor...\n");
                return 0;
            default:
                printf("Geçersiz komut.\n");
                break;
        }
    }
    return 0;
}

void yeni_dosya_olustur(const char *dosya_adi) {
    FILE *fp = fopen(dosya_adi, "w");
    if (fp == NULL) {
        printf("Dosya oluşturulamadı.\n");
        return;
    }
    printf("Dosya oluşturuldu: %s\n", dosya_adi);
    fclose(fp);
}

void dosyaya_yaz(const char *dosya_adi, const char *bilgi) {
    FILE *fp = fopen(dosya_adi, "a");
    if (fp == NULL) {
        printf("Dosya açılamadı.\n");
        return;
    }
    fprintf(fp, "%s\n", bilgi);
    printf("Bilgi yazıldı: %s\n", bilgi);
    fclose(fp);
}

void dosya_oku(const char *dosya_adi) {
    FILE *fp = fopen(dosya_adi, "r");
    if (fp == NULL) {
        printf("Dosya bulunamadı.\n");
        return;
    }
    char satir[256];
    while (fgets(satir, sizeof(satir), fp) != NULL) {
        printf("%s", satir);
    }
    fclose(fp);
}

void dosya_sil(const char *dosya_adi) {
    if (remove(dosya_adi) == 0) {
        printf("Dosya silindi: %s\n", dosya_adi);
    } else {
        printf("Dosya bulunamadı.\n");
    }
}

void kelime_ara(const char *dosya_adi, const char *kelime) {
    FILE *fp = fopen(dosya_adi, "r");
    if (fp == NULL) {
        printf("Dosya bulunamadı.\n");
        return;
    }
    char satir[256];
    int bulundu = 0;
    while (fgets(satir, sizeof(satir), fp) != NULL) {
        if (strstr(satir, kelime) != NULL) {
            printf("Kelime bulundu: %s", satir);
            bulundu = 1;
            break;
        }
    }
    if (!bulundu) printf("Kelime bulunamadı.\n");
    fclose(fp);
}

void kelime_degistir(const char *dosya_adi, const char *eski_kelime, const char *yeni_kelime) {
    FILE *fp = fopen(dosya_adi, "r");
    if (fp == NULL) {
        printf("Dosya bulunamadı.\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    char satir[256];
    while (fgets(satir, sizeof(satir), fp) != NULL) {
        char *pos = strstr(satir, eski_kelime);
        if (pos != NULL) {
            char yeni_satir[256];
            strncpy(yeni_satir, satir, pos - satir);
            yeni_satir[pos - satir] = '\0';
            strcat(yeni_satir, yeni_kelime);
            strcat(yeni_satir, pos + strlen(eski_kelime));
            fprintf(temp, "%s", yeni_satir);
        } else {
            fprintf(temp, "%s", satir);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(dosya_adi);
    rename("temp.txt", dosya_adi);
    printf("Kelime değiştirildi.\n");
}

void kelime_sil(const char *dosya_adi, const char *kelime) {
    FILE *fp = fopen(dosya_adi, "r");
    if (fp == NULL) {
        printf("Dosya bulunamadı.\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    char satir[256];
    while (fgets(satir, sizeof(satir), fp) != NULL) {
        char *pos = strstr(satir, kelime);
        if (pos != NULL) {
            char yeni_satir[256];
            strncpy(yeni_satir, satir, pos - satir);
            yeni_satir[pos - satir] = '\0';
            strcat(yeni_satir, pos + strlen(kelime));
            fprintf(temp, "%s", yeni_satir);
        } else {
            fprintf(temp, "%s", satir);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(dosya_adi);
    rename("temp.txt", dosya_adi);
    printf("Kelime silindi.\n");
}

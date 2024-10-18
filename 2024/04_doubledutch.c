#include <stdio.h>

#define MAX_SIZE 256

// Fonksiyon bildirimleri
int findFirstOccurrence(char str[], char aChar);
void insertChar(char str[], char aChar, int index);
void replaceChars(char str[], char sChar[], char rChar);
void transformString(char str[]);

int main() {
    char myString[MAX_SIZE] = "charcharcharchar";
    char command, tempChar, sChar[MAX_SIZE];
    int index;

    printf("** Welcome to the Double Dutch game **\n"); // Task 1

    while(1) {
        printf("Command? ");
        scanf(" %c", &command);

        switch (command) {
            case 'p': // String yazdır - Task 2
                printf("String: %s\n", myString);
                break;

            case 's': // Yeni string al - Task 3
                printf("Please enter a string: ");
                scanf(" %[^\n]s", myString);
                break;

            case 'f': // İlk geçen karakteri bul - Task 4
                printf("Please enter a character: ");
                scanf(" %c", &tempChar);
                index = findFirstOccurrence(myString, tempChar);
                if (index != -1) {
                    printf("'%c' found at index %d.\n", tempChar, index);
                } else {
                    printf("'%c' not found in string.\n", tempChar);
                }
                break;

            case 'i': // Belirli bir pozisyona karakter ekle - Task 5
                printf("Which character to insert: ");
                scanf(" %c", &tempChar);
                printf("At which position: ");
                scanf("%d", &index);
                while (index < 0 || index > MAX_SIZE) {
                    printf("Invalid position. Enter again: ");
                    scanf("%d", &index);
                }
                insertChar(myString, tempChar, index);
                break;

            case 'r': // Karakter(ler)i değiştir - Task 6
                printf("Which characters to replace: ");
                scanf("%s", sChar);
                printf("Replace with character: ");
                scanf(" %c", &tempChar);
                replaceChars(myString, sChar, tempChar);
                break;

            case 'g': // Stringi "Double Dutch" kurallarına göre dönüştür - Task 7
                transformString(myString);
                break;

            case 'q': // Programı sonlandır
                 return 0;

           //default gerekmiyor
        }
    }

    return 0;
}

// İlk geçen karakterin pozisyonunu bulma
int findFirstOccurrence(char str[], char aChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == aChar) {
            return i;
        }
    }
    return -1;
}

// Karakter ekleme fonksiyonu
void insertChar(char str[], char aChar, int index) {
    int length = 0;

    // Uzunluğu bulma
    while (str[length] != '\0') {
        length++;
    }

    // Sonraki karakterleri kaydırma
    for (int i = length; i >= index; i--) {
        str[i + 1] = str[i];
    }

    // Karakteri ekleme
    str[index] = aChar;
}

// Karakter değiştirme fonksiyonu
void replaceChars(char str[], char sChar[], char rChar) {
    int index, i = 0;

    // sChar dizisindeki her bir karakter için arama yap
    while (sChar[i] != '\0') {
        // str içinde sChar[i]'yi arayıp her birini değiştirene kadar devam et
        while ((index = findFirstOccurrence(str, sChar[i])) != -1) {
            // Karakter bulunduysa, rChar ile değiştir
            str[index] = rChar;
        }
        i++;
    }
}

// String dönüştürme fonksiyonu
void transformString(char str[]) {
    char result[MAX_SIZE * 3]; // Fazladan yer ayırdık
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        // Küçük harfli ünlüleri 'E' ile değiştir
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            result[j++] = 'E';
        }
        // Boşluk karakterini '-ay' ile değiştir
        else if (str[i] == ' ') {
            result[j++] = '-';
            result[j++] = 'a';
            result[j++] = 'y';
        } else {
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; // Sonlandırma
    for (i = 0; result[i] != '\0'; i++) {
        str[i] = result[i];
    }
    str[i] = '\0';
}

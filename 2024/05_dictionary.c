#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_WORDS 10 // Sözlük kapasitesi 10 kelimelik
#define MAX_LENGTH 255      // Her kelime azami 255 karakter uzunluğunda olabilir

//strlen fonksiyonunu kullanmadan kelime uzunlugunu bulmak icin fonksiyon.
int uzunlukBul(char *word) {
    int uzunluk = 0;

    while (word[uzunluk] != '\0') {
        uzunluk++;
    }

    return uzunluk;
}

// Sözlüğe kelime ekleyen fonksiyon
void addWord(char *dict[], char *word) {
    int i = 0;

    // Boş yer bulma (NULL olan pozisyon)
    while (i < MAX_NUMBER_WORDS && dict[i] != NULL) {
        i++;
    }

    // Eğer dizide boş yer varsa
    if (i < MAX_NUMBER_WORDS) { // kelime için bellekte yer ayır
        // Kelimenin uzunluğunu bul
        int length = uzunlukBul(word);

        dict[i] = (char *)malloc((length + 1) * sizeof(char));  // Hafıza ayır

        // Tedbir olarak bellekte yer yoksa hata versin
        if (dict[i] == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        // Kelimeyi kopyala
        for (int j = 0; j <= length; j++) {
            dict[i][j] = word[j];  // Karakterleri teker teker kopyala
        }

        printf("Word '%s' added at index %d.\n", word, i);
    } else {
        printf("Dictionary already full.\n");  // Eğer boş yer yoksa hata mesajı
    }
}

// Sözlüğü yazdıran fonksiyon
void printDict(char *dict[]) {
    printf("Dictionary:\n");
    for (int i = 0; i < MAX_NUMBER_WORDS; i++) {
        if (dict[i] != NULL) {
            printf("- %s\n", dict[i]);  // Dolu girişleri yazdır
        } else {
            printf("empty\n");  // Boş girişler için 'empty' yaz
        }
    }
}

// Sözlükte kelime arayan fonksiyon
int findWordInDict(char *dict[], char *word) {
    for (int i = 0; i < MAX_NUMBER_WORDS; i++) {
        if (dict[i] != NULL) {
            int j = 0;
            while (dict[i][j] == word[j] && word[j] != '\0' && dict[i][j] != '\0') {
                j++;
            }
            if (word[j] == '\0' && dict[i][j] == '\0') {
                return i;  // Kelime bulundu, index'i döndür
            }
        }
    }
    return -1;  // Kelime bulunamadıysa -1 döndür
}

// Sözlükten kelime çıkaran fonksiyon
void removeWord(char *dict[], char *word) {
    int index = findWordInDict(dict, word);

    if (index != -1) {
        free(dict[index]);  // Bellekte ayrılan yeri serbest bırak
        dict[index] = NULL;  // İlgili dizin boş hale getir
        printf("Word '%s' removed from dictionary.\n", word);
    } else {
        printf("Word not found in dictionary.\n");
    }
}

// İki kelimeyi takaslayan fonksiyon
void swapWords(char *dict[], int index1, int index2) {
    // En az biri eksikse hata mesajı
    if (index1 == -1 || index2 == -1) {
        printf("Cannot swap words. At least one word missing in the dictionary.\n");
        return;
    }

    // Kelimeleri değiştir
    char *temp = dict[index1];
    dict[index1] = dict[index2];
    dict[index2] = temp;

 }

// Sözlükteki kelimeleri alfabetik sıraya göre sıralayan fonksiyon
void orderAlphabeticalDict(char *dict[]) {
    for (int i = 0; i < MAX_NUMBER_WORDS - 1; i++) {
        for (int j = 0; j < MAX_NUMBER_WORDS - i - 1; j++) {
            if (dict[j] != NULL && dict[j + 1] != NULL) {
                if (strcmp(dict[j], dict[j + 1]) > 0) {
                    // swapWords fonksiyonunu kullanarak kelimeleri yer değiştir
                    swapWords(dict, j, j + 1);
                }
            }
        }
    }
    printf("Dictionary has been ordered alphabetically.\n");
}

int main() {
    char *dictionary[MAX_NUMBER_WORDS] = {};  // Sözlük dizisini NULL ile başlat
    char command;
    char word[MAX_LENGTH];  // Kullanıcının eklemek, aramak veya silmek istediği kelimeyi saklayacak
    char word1[MAX_LENGTH], word2[MAX_LENGTH];  // Swap için kullanılacak iki kelime

    // Karşılama mesajını yazdır
    printf("** Dictionary **\n"); // Task 1

    while (1) {  // Sonsuz döngü, komutları işle
        printf("Command? ");
        scanf(" %c", &command);  // Kullanıcıdan komutu al

        switch (command) {
			
			case 'q':  // 'q' komutu ile programı sonlandır - Task 2
                return 0;

            case 'p':  // 'p' komutu ile sözlüğü yazdır - Task 3
                printDict(dictionary);
                break;

            case 'a':  // 'a' komutu ile sözlüğe kelime ekle - Task 4
                printf("Add word? ");
                scanf("%s", word);  // Kelimeyi al
                addWord(dictionary, word);  // Kelimeyi sözlüğe ekle
                break;

            case 'f':  // 'f' komutu ile kelime ara - Task 5
                printf("Find word? ");
                scanf("%s", word);  // Aranacak kelimeyi al
                int index = findWordInDict(dictionary, word);
                if (index != -1) {
                    printf("Found word at index %d.\n", index);  // Kelime bulundu
                } else {
                    printf("Word not in dictionary.\n");  // Kelime bulunamadı
                }
                break;

            case 'r':  // 'r' komutu ile kelimeyi çıkar - Task 6
                printf("Remove word? ");
                scanf("%s", word);  // Silinecek kelimeyi al
                removeWord(dictionary, word);  // Kelimeyi sözlükten çıkar
                break;

            case 's':  // 's' komutu ile iki kelimeyi değiştir - Task 7
                printf("Swap two words:\n");
                printf("Enter first word? ");
                scanf("%s", word1);  // İlk kelimeyi al
                printf("Enter second word? ");
                scanf("%s", word2);  // İkinci kelimeyi al
                int index1 = findWordInDict(dictionary, word1);
                int index2 = findWordInDict(dictionary, word2);
                swapWords(dictionary, index1, index2);  // Kelimeleri değiştir
                break;
                
            case 'o':  // 'o' komutu ile sözlüğü alfabetik sıraya göre sırala - Task 8
                orderAlphabeticalDict(dictionary);
                break;
				
            //default gerekmiyor.
        }
    }

    return 0;
}

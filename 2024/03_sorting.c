#include <stdio.h>

// Dizi elemanlarını ekrana basar. Her eleman üç ondalık basamaklı olarak yazdırılır.
void printValues(float values[], int size) {
    printf("Values: ");
    // Tüm dizi elemanlarını sırayla yazdırıyoruz.
    for (int i = 0; i < size; i++) {
        printf("%.3f", values[i]); // Elemanları üç basamaklı olacak şekilde yazdırır.
        if (i < size - 1) {
            printf(", "); // Her eleman arasında virgül koyar.
        }
    }
    printf("\n");
}

// Verilen bir değerin dizide en son bulunduğu indeksi döner. Bulunamazsa -1 döner.
int findLastIndexOfValue(float values[], int size, float v) {
	// Diziyi tersten dolaşıp, en son bulunan değerin indeksini bulur.
	for (int i = size - 1; i >= 0; i--) {
		if (values[i] == v) {
            return i; // Değer bulunduğunda, o indeksi döner.
        }
    }
    return -1;
}

// Dizideki en büyük elemanı bulur.
float maxElement(float values[], int size) {
    float maxVal = values[0]; // İlk elemanı en büyük kabul ederek başlıyoruz.
	
	// Tüm elemanları karşılaştırıp en büyüğünü buluyoruz.
    for (int i = 1; i < size; i++) {
        if (values[i] > maxVal) {
            maxVal = values[i]; // Daha büyük bir değer bulunduğunda maxVal güncellenir.
        }
    }
    return maxVal; // En büyük değer döner.
}

// Verilen indeksteki elemanı yeni bir değerle değiştirir.
void replaceElement(float values[], int i, float v) {
    values[i] = v; // İlgili indeksteki değeri yeni değerle değiştir.
}

// Bubble sort algoritmasıyla diziyi sıralar.
void sortOnValue(float values[], int size) {
    int swapped; // Bir turda değişim olup olmadığını kontrol etmek için kullanılan değişken.
    
	// Dizi tamamen sıralanana kadar döneriz.
	do {
        swapped = 0; // Her yeni turda değişim yapılmadığını varsayıyoruz.
        // Diziyi baştan sona kadar dolaşıp bitişik elemanları karşılaştırıyoruz.
        for (int i = 0; i < size - 1; i++) {
            // Eğer bir eleman bir sonrakinden büyükse yer değiştiriyoruz.
            if (values[i] > values[i + 1]) {
                float temp = values[i]; // Geçici değişken kullanarak değiş tokuş yapıyoruz.
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swapped = 1; // Bir değişim olduğu için swapped'i 1 yapıyoruz.
            }
        }
    } while (swapped); // Hiçbir değişim olmayana kadar döngü devam eder.
}

// Ana program
int main() {
    char command; // Kullanıcının girdiği komut burada saklanır.
    float val[10] = {1.5, 2.2, 7.3, 9.2, 7.4, 7.5, -8.0, 1.5, 12.0};  // Dizinin ilk 9 elemanı tanımlandı. 10. eleman otomatik olarak 0.0 olacaktır.

    // Program 'q' komutu girilene kadar döner.
    while (1) {
        printf("Command? ");
        scanf(" %c", &command);

        // Komutlara göre işlemler switch-case yapısı ile yönetiliyor.
        switch (command) {
            case 'q':  // 'q' komutu programdan çıkış yapar.
                return 0;

            case 'p':  // 'p' komutu diziyi ekrana yazdırır.
                printValues(val, 10);
                break;

            case 'f': {  // 'f' komutu bir değeri bulur.
                float valueToFind;
                printf("Find value: ");
                scanf("%f", &valueToFind);
                
                int index = findLastIndexOfValue(val, 10, valueToFind);
                if (index != -1) {
                    printf("Value found at index %d in array.\n", index);
                } else {
                    printf("Value not found in array!\n");
                }
                break;
            }

            case 'm':  // 'm' komutu dizideki en büyük elemanı bulur ve yazdırır.
                printf("Max: %.3f\n", maxElement(val, 10));
                break;

            case 'r': {  // 'r' komutu dizideki bir elemanı değiştirmeye yarar.
                int index;
                float newValue;
                do {
                    printf("Replace (index): ");
                    scanf("%d", &index);
                    if (index < 0 || index >= 10) {
                        printf("Error: index exceeds bound of array.\n");
                    }
                } while (index < 0 || index >= 10);

                printf("Replace (value): ");
                scanf("%f", &newValue);
                replaceElement(val, index, newValue);
                break;
            }

            case 's':  // 's' komutu diziyi sıralar.
                sortOnValue(val, 10);
                break;

            default:  // Tanınmayan bir komut girilirse uyarı mesajı yazdırılır.
                printf("Invalid command!\n");
                break;
        }
    }
	
	return 0;
}

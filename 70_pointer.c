#include <stdio.h>
#include <string.h>

void main(){

    system("cls");

    int sayi = 5534;

    int* ptr = &sayi;

    

    printf("*ptr pointerin gosterdigi adresteki deger %d\n", *ptr);
    
    printf("ptr decimal adresi %d\n", ptr);
    
    printf("ptr hexadecimal adresi %x\n", ptr);

}
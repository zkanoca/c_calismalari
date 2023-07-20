#include <stdio.h>
#include <ctype.h>

int main()
{

    char harf;

    printf("Bir harf yaziniz [A], [B], [C], [D] :  ");

    scanf("%c", &harf);

    // harf = 'c';

    harf = toupper(harf);

    switch (harf)
    {
    case 'A':
    // case 'a':
        printf("\nA harfi girildi.");
        break;
    case 'B':
    // case 'b':
        printf("\nB harfi girildi.");
        break;
    case 'C':
    // case 'c':
        printf("\nC harfi girildi."); 
        break;
    case 'D':
    // case 'd':
        printf("\nD harfi girildi.");
        break;
    default:
        printf("\nFarkli bir karakter girdiniz.");
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int intX = 12;
    float floatY = 5; 
    double doubleZ = 8;
    char charA = 'A';

    printf("intX'in haf�zada kaplad��� yer: %lu byte\n", sizeof(intX));
    printf("floatY'nin haf�zada kaplad��� yer: %lu byte\n", sizeof(floatY));
    printf("doubleZ'nin haf�zada kaplad��� yer: %lu byte\n", sizeof(doubleZ));
    printf("charA'n�n haf�zada kaplad��� yer: %lu byte\n", sizeof(charA));

    return 0;
}

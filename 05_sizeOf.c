#include <stdio.h>

int main()
{
    int intX = 12;
    float floatY = 5; 
    double doubleZ = 8;
    char charA = 'A';

    printf("intX'in hafızada kapladığı yer: %lu byte\n", sizeof(intX));
    printf("floatY'nin hafızada kapladığı yer: %lu byte\n", sizeof(floatY));
    printf("doubleZ'nin hafızada kapladığı yer: %lu byte\n", sizeof(doubleZ));
    printf("charA'nın hafızada kapladığı yer: %lu byte\n", sizeof(charA));

    return 0;
}
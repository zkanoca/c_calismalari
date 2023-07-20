#include <stdio.h>

int main()
{
    int intX = 12;
    float floatY = 5; 
    double doubleZ = 8;
    char charA = 'A';

    printf("intX'in hafýzada kapladýðý yer: %lu byte\n", sizeof(intX));
    printf("floatY'nin hafýzada kapladýðý yer: %lu byte\n", sizeof(floatY));
    printf("doubleZ'nin hafýzada kapladýðý yer: %lu byte\n", sizeof(doubleZ));
    printf("charA'nýn hafýzada kapladýðý yer: %lu byte\n", sizeof(charA));

    return 0;
}

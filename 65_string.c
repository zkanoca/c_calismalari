#include <stdio.h>
#include <string.h>

void main()
{
    char gun[30] = {'P', 'e', 'r', 's', 'e', 'm', 'b', 'e', '\0'};

    printf("gun: %s\n", gun);

    printf("gun degiskeninin uzunlugu\t\t\t:\t%d\n", sizeof(gun));
    printf("gun degiskeninin hafizada kapladigi uzunluk\t:\t%d\n", strlen(gun));
}
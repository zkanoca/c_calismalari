#include <stdio.h>
#include <string.h>

void main()
{
    char gun[] = {'P', 'e', 'r', 's', 'e', 'm', 'b', 'e', '\0'};
    int uzunluk = sizeof(gun);
    char gun2[uzunluk];

    strcpy(gun2, gun); // strcpy(hedef, kaynak)

    printf("gun: %s\ngun2: %s\n", gun, gun2);

    printf("%d", uzunluk);
    
}
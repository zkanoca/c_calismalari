#include <stdio.h>
#include <string.h>

void main()
{
    char gun[10] = {'P', 'e', 'r', 's', 'e', 'm', 'b', 'e', '\0'};
    char gun2[10] = " gunu";

    // string concatenation
    strcat(gun, gun2); // strcat(asil, [eklenecek ifade])

    printf("%s\n", gun);
}
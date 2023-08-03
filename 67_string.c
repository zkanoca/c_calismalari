#include <stdio.h>
#include <string.h>

void main()
{
    char gun[] = {'C', 'u', 'm', 'a', 'r', 't',
                     'e', 's', 'i', '\0'};

    // char abece[] = "abcdefghijklmnopqrstuvwxyz";

    char *aranan;

    char *sira;

    aranan = strstr(strlwr(gun), "art");

    sira = strchr(strlwr(gun), "c");

    printf("\naranan:  %s ", aranan); 
    printf("\nc harfi sirasi:  %d ", aranan); 


}
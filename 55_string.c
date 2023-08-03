#include <stdio.h>

void main()
{

    char s[11] = "kerem ayhan";

    int i = 0, say = 0;

    // while (i < 11)
    while (s[i] != '\0')
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            say++;
        }
        i++;
    }

    printf("Sesli harf sayisi %d", say);
}
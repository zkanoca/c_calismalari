#include <stdio.h>
#include <string.h>

void main()
{
    char metin[30];

    printf("Adinizi yaziniz: ");
    gets(metin);

    puts(metin);

    //strlwr --> string lowercase karakterler (küçük harfler)
    puts("Adinizin kucuk harflerle yazilmis sekli");
    puts(strlwr(metin)); 

    puts("Adinizin buyuk harflerle yazilmis sekli");
    puts(strupr(metin));

}
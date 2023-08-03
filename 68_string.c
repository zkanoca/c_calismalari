#include <stdio.h>
#include <stdio.h>

void main()
{

    char cumle1[24] = "Bugun";
    char cumle2[24] = " gunlerden Persembe";

    char *birlesmisCumle = strncat(cumle1, cumle2, 10);

    // cumle1 ardına cumle2'yi ekle
    //  printf("%s\n", strcat(cumle1, cumle2));

    // cumle1 ardına cumle2'nin ilk 10 karakterini ekle
    printf("%s\n", birlesmisCumle);

    /***************************************************************/
    printf("/***************************************************************/\n");
    char s1[40] = "ben s1 stringiyim";
    char s2[40] = "ben de s2 stringi icine kopyalanacagim";

    // s1 icine s2 string ifadesini kopyala
    //  char *kopya = strcpy(s1, s2);

    // s1 icine s2 string ifadesinin ilk 10 karakterini kopyala
    char *kopya = strncpy(s1, s2, 17);

    printf("%s\n", kopya);

    /************************************************/

    printf("/***************************************************************/\n");

    char ifade[40] = "Ben ornek bir ifade cumlesiyim.";

    printf("%s\n", strchr(ifade, 'c'));
}
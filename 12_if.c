#include <stdio.h>

int main()
{

    int a = 3, b = 5, c = 6;

    if (a > b)
    {
        if (a > c)
        {
            printf("a hem b'den hem de c'den buyuktur.\n");
        }
    }
    else if (b > c)
    {
        if (b > a)
        {
            printf("b hem a'dan hem de c'den buyuktur.\n");
        }
    }

    if (a > b && a > c)
        printf("a hem b'den hem de c'den buyuktur.\n");
    else if (b > c && b > a)
        printf("b hem a'dan hem de c'den buyuktur.\n");

    return 0;
}
#include <stdio.h>

int toplama(int n);

int main()
{
    int n;

    printf("Son terim sayisini yaziniz: ");
    scanf("%d", &n);

    printf("\n1 - %d  arasi sayilarin toplami %d olarak hesaplanmistir.\n", n, toplama(n));
}

int toplama(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (n > 1)
    {
        return n + toplama(n - 1);
    }
}
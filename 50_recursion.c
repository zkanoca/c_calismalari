#include <stdio.h>

int faktoriyel(int n);


int main()
{
    int n, f;

    printf("Faktoriyeli hesaplanacak sayiyi yaziniz: ");
    scanf("%d", &n);

    f = faktoriyel(n);

    printf("\n%d sayisinin faktoriyeli %d olarak hesaplanmistir.\n", n, f);
}

int faktoriyel(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (n > 1)
    {
        return n * faktoriyel(n - 1);
    }
}
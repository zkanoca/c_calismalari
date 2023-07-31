#include <stdio.h>

void fibonacci(int n);

int main()
{
    int n;
    printf("Terim sayisini yaziniz: ");
    scanf("%d", &n);
    printf("Fibonacci Serisi Terimleri\n");
    printf("--------------------------\n");
    printf("%d, %d", 0, 1);

    fibonacci(n - 2);
}

void fibonacci(int n)
{
    static int n1 = 0, n2 = 1, n3;

    if (n > 0)
    {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
        printf(", %d", n3);
        fibonacci(n - 1);
    }
}
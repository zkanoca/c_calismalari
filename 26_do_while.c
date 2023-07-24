#include <stdio.h>

// while dongusu ile fibonacci serisi oluşturma
int main()
{

    int sinirTerim, i = 0, fibo = 0, terim1 = 0, terim2 = 1;

    printf("Fibonacci serisinin kac adimini istersiniz: ");
    scanf("%d", &sinirTerim);

    do
    {

        printf("%d\n", fibo);
        terim1 = terim2;
        terim2 = fibo;
        fibo = fibo + terim1;

        i++;
    } while (i < sinirTerim);
    return 0;
}
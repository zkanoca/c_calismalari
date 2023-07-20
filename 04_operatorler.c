#include <stdio.h>

int main()
{
    int x = 12;
    int y = 5; 
    int z = 8;

    printf("%d\n", x > y); //1
    printf("%d\n", x < y); //0
    printf("%d\n", x != y); //1
    printf("%d\n", x == y); //0
    printf("%d\n", x >= y); //1
    printf("%d\n", x <= y); //0
    



    printf("%d\n", x <= y && z > y); //0
    printf("%d\n", x == y || z != y); //1
     
    
    

    return 0;
}
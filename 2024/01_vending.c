#include <stdio.h>

int main()
{
	char c, sugar, payment;
	int coin1, coin2;
	printf("My first vending machine.\n");

	while(1)
	{
		printf("Coffee or tea? (c/t/q)\n");

		scanf(" %c", &c);

		printf("You entered: '%c'\n", c);

		if(c== 'q') {
			printf("Bye!\n");
			break;

		} else if(c=='t')
		{
			printf("Dispense tea.\n");
		}
		else if(c== 'c')
		{
			printf("Coffee it is.\n");
			printf("With sugar= (y/n)");

			scanf(" %c", &sugar);

			if(sugar == 'y')
			{
				printf("Pay 2 euro with cash.\n");

				printf("Coin inserted? (1/2) ");
				scanf("%d", &coin1);

				if(coin1 == 2)
				{
					printf("Dispense coffee without sugar.\n");
				}
				else if(coin1 == 1)
				{
					printf("One more please.\n");
					printf("Coin inserted? (1/2) ");
					scanf("%d", &coin2);
					printf("You entered: '%d'\n", coin2);

					if(coin2 == 1)
					{
						printf("Dispense coffee without sugar.\n");
					}
					else if(coin2 == 2)
					{
						printf("Dispense coffee with sugar.\n");

					}
				}
			}
			else {  //sugar == n
				do {
					printf("Pay with card.\n");
					
					printf("Payment successful? (y/n) ");

					scanf(" %c", &payment);
					
					printf("You entered: '%c'\n", payment);
					
				} while(payment == 'n');

				printf("Dispense coffee without sugar.\n");
			}
		}

	}
	return 0;
}

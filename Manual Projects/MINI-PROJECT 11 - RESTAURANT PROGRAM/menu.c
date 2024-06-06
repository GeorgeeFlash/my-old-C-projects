#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) 
{
	// Declaration of variables
	// I will have to declare a price, number of items ordered and total price variable for each food as well as total price for all
	// The numbers represent each food item on the choise list in their orders
	int choise;
	int totalPrice = 0;
	int priceOf1 = 500;
	int num1 = 0;
	int priceForChoise1 = 0;
	int priceOf2 = 1000;
	int num2 = 0;
	int priceForChoise2 = 0;
	int priceOf3 = 500;
	int num3 = 0;
	int priceForChoise3 = 0;
	int priceOf4 = 500;
	int num4 = 0;
	int priceForChoise4 = 0;
	int priceOf5 = 700;
	int num5 = 0;
	int priceForChoise5 = 0;
	int priceOf6 = 500;
	int num6 = 0;
	int priceForChoise6 = 0;
	int priceOf7 = 300;
	int num7 = 0;
	int priceForChoise7 = 0;
	int priceOf8 = 500;
	int num8 = 0;
	int priceForChoise8 = 0;
	int priceOf9 = 1000;
	int num9 = 0;
	int priceForChoise9 = 0;
	
	// While loop to continue  looping  until user quits
	
	while(true)
	{
		printf("List of Choises: \n");
		printf("1 Achu\n");
		printf("2.Water fufu and Eru\n");
		printf("3.Fufu and Vegetable\n");
		printf("4.Chicken\n");
		printf("5.Fish\n");
		printf("6.Meat\n");
		printf("7.Jellof rice\n");
		printf("8.Rice and Stew\n");
		printf("9.Ndole and White Yam\n");
		printf("10.Quit\n");
		scanf("%d", &choise);
		
		// switch statement to take users choise, compute results and print the table/menu
		switch(choise)
		{
			case 1:
				printf("How many plates of Achu do you want: ");
				scanf("%d", &num1);
				priceForChoise1 = num1 * priceOf1;
				break;
			case 2:
				printf("How many plates of Water fufu and Eru do you want: ");
				scanf("%d", &num2);
				priceForChoise2 = num2 *priceOf2;
				break;
			case 3:
				printf("How many plates of  Fufu and Vegetable do you want: ");
				scanf("%d", &num3);
				priceForChoise3 = num3 * priceOf3;
				break;
			case 4:
				printf("How many slises of Chicken do you want: ");
				scanf("%d", &num4);
				priceForChoise4 = num4 * priceOf4;
				break;
			case 5:
				printf("How many plates of Fish do you want: ");
				scanf("%d", &num5);
				priceForChoise5 = num5 * priceOf5;
				break;
			case 6:
				printf("How many slises of Meat do you want: ");
				scanf("%d", &num6);
				priceForChoise6 = num6 * priceOf6;
				break;
			case 7:
				printf("How many plates of Jellof Rice do you want: ");
				scanf("%d", &num7);
				priceForChoise7 = num7 * priceOf7;
				break;
			case 8:
				printf("How many plates of Rice and Stew do you want: ");
				scanf("%d", &num8);
				priceForChoise8 = num8 * priceOf8;
				break;
			case 9:
				printf("How many plates of Ndole and White Yam do you want: ");
				scanf("%d", &num9);
				priceForChoise9 = num9 * priceOf9;
				break;
			case 10:
				printf("\nYour menu:\n");
				printf("%d Plate(s) of Achu\t\t\t(%d)\n", num1, priceForChoise1 );
				printf("%d Plate(s) of water fufu and Eru\t(%d)\n", num2, priceForChoise2);
				printf("%d Plate(s) of Fufu and Vegetable\t(%d)\n", num3, priceForChoise3 );
				printf("%d Slice(s) of Chicken\t\t\t(%d)\n", num4, priceForChoise4);
				printf("%d Plate(s) of Fish\t\t\t(%d)\n", num5, priceForChoise5 );
				printf("%d Slice(s) of Meat\t\t\t(%d)\n", num6, priceForChoise6);
				printf("%d plate(s) of Jellof Rice\t\t(%d)\n", num7, priceForChoise7 );
				printf("%d plate(s) of Rice and Stew\t\t(%d)\n", num8, priceForChoise8);
				printf("%d plate(s) of Ndole and White Yam\t(%d)" ,num9, priceForChoise9 );
				
				totalPrice = priceForChoise1+priceForChoise2+priceForChoise3+priceForChoise4+priceForChoise5+priceForChoise6+priceForChoise7+priceForChoise8+priceForChoise9;
				printf("\nTotal Price = \t\t\t\t%d Fcfa\n", totalPrice);
				if(totalPrice == 0)
				{
					printf("You didn't order anything :(. Please do reconsider and we assure you, you won't regret it!");
				}else
				{
					printf("Enjoy your meal! Hope to see you again :).\n");
				}
				exit(0);
			default:
				printf("Please enter a choise from above.\n");
				break;
		}
	}
	
	
	return 0;
}

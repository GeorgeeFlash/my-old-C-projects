#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() 
{
	system("color 3F");
	int pin=1234, option, enteredPin, count=0, amount=1;
	float balance = 5000;
	int continueTransaction = 1;
	
	time_t now;
	time(&now);
	printf("\n");
	printf("\t\t\t\t\t%s", ctime(&now));
	printf("\n\t\t\t\t=============*Welcome to Flash Tech*==============");
	
	while(pin != enteredPin)
	{
		printf("\nPlese enter your pin: ");
		scanf("%d", &enteredPin);
		if(enteredPin != pin)
		{
			Beep(610,500);
			printf("Invalid Pin!!!");
		}
		count++;
		if(count == 3 && pin != enteredPin){
			exit(0);
		}
	}
	while(continueTransaction != 0){
		printf("\n\t\t\t\t=============*Available Transactions*=============");
		printf("\n\n\t\t1. Withdraw");
		printf("\n\t\t2. Deposit");
		printf("\n\t\t3. Check Balance");
		printf("\n\n\tPlease select the option: ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				while(amount % 500 != 0){
					printf("\n\tEnter the amount: ");
					scanf("%d", &amount);
					if(amount % 500 != 0){
						printf("\n\tThe amount should be a multiple of 500!");
					}
				}
				if(balance < amount){
					printf("\n\t Sorry insufficient balance");
					amount = 1;
					break;
				}
				else {
					balance -= amount;
					printf("\n\tYou have withdrawn %d FCFA. Your new balance is %.2f FCFA", amount, balance);
					printf("\n\n\t\t\t\t===========*Thank you for banking with Flash Tech*===========");
					amount = 1;
					break;
				}
			case 2:
				printf("\n\t\tPlease enter the amount: ");
				scanf("%d", &amount);
				balance += amount;
				printf("\n\t\tYou have deposited %d FCFA. Your new balance is %.2f FCFA", amount, balance);
				printf("\n\n\t\t\t\t===========*Thank you for banking with Flash Tech*===========");
				amount = 1;
				break;
			case 3:
				printf("\n\t\tYour balance is %.2f", balance);
				printf("\n\n\t\t\t\t===========*Thank you for banking with Flash Tech*===========");		
				break;
				
			default:
				Beep(610,500);
				printf("Invalid option");
				
		}
		printf("\n\t\tDo you wish to perform another transaction? 1[Yes], 0[No]: ");
		scanf("%d", &continueTransaction);
		
	}
	return 0;
}
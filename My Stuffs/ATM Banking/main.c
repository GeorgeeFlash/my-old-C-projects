#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//#include <string.h> Turns out this is not really needed as well as the stdlib.h - but hey i'll just leave it there; you know!? 

/*Ok, i want to create an ATM Banking console App in which one would have three options:
 Withdraw,  Deposit,  and Check Balance
 You would also need a password to login*/

int main()
{
	system("color 3F");
	float balance = 10000;
	int amount, pin=1234, count = 0, enteredPin, option;
	char response = ' ';
	
	time_t now;
	time(&now);
	printf("\n");
	printf("\n\t\t\t\t\t%s", ctime(&now));
	
	printf("\t\t\t===============*Welcome To Flash Bank*===============");
	
	do
	{
		printf("\nPlease enter pin: ");
		scanf("%d", &enteredPin);
		
		if(enteredPin != pin)
		{ 
			Beep(650,400);
			printf("Invalid pin\n");
			count++;
			
			if(count == 3 && enteredPin != pin)
			{
				printf("\nYou've entered the wrong pin more than three times!\n");
				exit(0);
			}
		}
	} while(pin != enteredPin);
	
	do
	{
		system("cls");
		printf("\nPlease enter preferred option!\n");
		printf("==================");
		printf("\n1. Withdraw");
		printf("\n2. Deposit");
		printf("\n3. Check Balance");
		printf("\n4. Exit");
		printf("\n==================\n");
		printf("\n");
		
		printf("Option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				do
				{
					printf("Enter amount you want to withdraw: ");
					scanf("%d", &amount);
					
					if(amount % 500 != 0)
					{
						printf("The amount should be a multiple of 500!\n");
					}
					else
					{
						balance -= amount;
						printf("\nYou have withdrawn %dFCFA. Your new balance is %.2fFCFA\n", amount, balance);
						amount = 0;
					}
				} while(amount % 500 != 0);
				break;
			case 2:
				printf("Enter amount you want to deposit: ");
				scanf("%d", &amount);
				
				balance += amount; 
				printf("\nYou have just deposited %dFCFA. Your new balance is %.2fFCFA\n", amount, balance);
				amount = 0;
				break;
			case 3:
				printf("\nYour balance is %.2fFCFA", balance);
				break;
			case 4:
				printf("So Soon? :( We would love to see you sooner :)");
				exit(0);
			default:
				Beep(650,300);
				printf("\nInvalid option! Please enter an option from above!\n");
				break;
		}	
		
		fgetc(stdin);
		printf("\nDo you wish to perform another operation? [Y/N]: ");
		scanf("%c", &response);
		response = toupper(response);
		
	} while (response == 'Y');	
	
	return 0;
}

#include <stdio.h>
#include <windows.h>
#include <time.h>

int main(void)
{
	int count = 0;
	
	int pin = 1234;
	int password;
	int continueTransaction = 1;
	int operation;
	int option;
			time_t now;
		time(&now);
	printf("%s",ctime(&now));
	while(pin!= password){
	printf("enter your password: \n");
	scanf("%d", &password);
	if(pin != password){
		Beep(610,500);
		printf("Invalide password\n");
	}
	count ++;
	if(count == 3 && pin != password){
		exit(0);
	}
}
	
	while(continueTransaction != 0 ){
		printf("main menu\n");
		printf("\n\t\t\t1.call");
		printf("\n\t\t\t2.send\n");
		printf("enter your option:");
		scanf("%d", &option);
	
		switch(option){
			case 1:
				printf("call contact\n");
				break;
			case 2:
			printf("send message\n");
				break;
			default:
				Beep(610,500);
			printf("Invalid option!!!\n");	
				
		}
			printf("do you wish to perform another operation? 1(Yes), 0(No): ");
		scanf("%d", &continueTransaction);
	}



 return 0;
}

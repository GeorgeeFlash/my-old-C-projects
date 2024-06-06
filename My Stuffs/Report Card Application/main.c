#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int passwordVerification(char[]);

int main() 
{
	int age;
	char name[25], pass[5] = "1234";
	int entered = 0, n;
	
	do
	{
		printf("\nEnter Your name:\t");
		scanf("%s", &name);
		
		printf("\nEnter You age:\t");
		scanf("%d", &age);
		entered = 1;
	} while(entered == 0);
	
	passwordVerification(pass);
	
	printf("Enjoy Your Time With Us!!\n\n");
	
	return 0;
}

int passwordVerification(char pass[])
{
	char checkPass[5];
	int countFlag = 0;
	do
	{
		printf("\nEnter Your Password:\t");
		scanf("%s", &checkPass);
		
		fgetc(stdin);
		
		if(strcmp(checkPass,pass) == 1 && countFlag < 3)
		{
			printf("\nWrong pass! Please try again!\n");
		}
		
		if(countFlag == 3)
		{
			printf("\n\tTRIED MORE THAN THREE TIMES!!!\n");
			printf("Please Try Again Later\n");
			exit(0);
		}
		countFlag++;
		
	} while(strcmp(checkPass,pass) == 1);
	
	printf("\nYou Have Succefully Logged Into Your Account :)\n");
	
	return 0;
}

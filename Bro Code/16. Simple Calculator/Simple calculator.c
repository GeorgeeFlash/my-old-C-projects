#include <stdio.h>

int main()
{
	char operation;
	double num1;
	double num2;
	double result;
	
	printf("Enter an operator (+ - / *): ");
	scanf("%c", &operation);
	
	printf("Enter number 1: ");
	scanf("%lf", &num1);
	
	printf("Enter number 2: ");
	scanf("%lf", &num2);
	
	switch(operation)
	{
		case '+':
			result = num1 + num2;
			printf("\nResult: %.2lf", result);
			break;
		case '-':
			result = num1 - num2;
			printf("\nResult: %.2lf", result);
			break;
		case '/':
			result = num1 / num2;
			printf("\nResult: %.2lf", result);
			break;
		case '*':
			result = num1 * num2;
			printf("\nResult: %.2lf", result);
			break;	
		default:
			printf("%c is not valid!\n");
	}
	
	return 0;
}

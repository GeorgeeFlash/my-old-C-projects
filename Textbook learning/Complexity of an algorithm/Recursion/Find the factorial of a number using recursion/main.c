#include <stdio.h>

int factor(int);
void main()
{
	int x = 5, fact;
	fact = factor(x);
	printf("\nFactorial is =  %d", fact);
	
}
int factor (int y)
{
	int a;
	if(y==1)
		return 1;
	else
		a = y * factor(y-1);
		
	return (a);
	
}
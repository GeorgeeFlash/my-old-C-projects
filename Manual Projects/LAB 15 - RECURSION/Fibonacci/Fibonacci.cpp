#include <stdio.h>

int fib1(int y);
int fib2(int y);
int index = 0;


int main()
{
	int n, fibonacci1, fibonacci2;
	
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	
	fibonacci1 = fib2(n);
	fibonacci2 = fib1(n);
	
	printf("\n\nThe Fibonacci of %d is %d. Using fib2", n, fibonacci1);
	printf("\nThe Fibonacci of %d is %d. Using fib1\n", n, fibonacci2);
	
	return 0;
}
int fib1(int y)
{
	index ++;
	printf("Fib(%d)\n", y); 
	printf("There were %d calls\n", index);
	
	if(y == 0)
		return 0;
	else if(y == 1)
		return 1;
	else
		return fib1(y-1) + fib1(y-2); 	
}
int fib2(int y)
{
	int i;
	int array[y];
	
	array[0] = 0;
	array[1] = 1;
	
	for(i=2; i<=y; i++)
	{
		array[i] = array[i-1] + array[i-2];
	}
	
	return array[y];
	
}

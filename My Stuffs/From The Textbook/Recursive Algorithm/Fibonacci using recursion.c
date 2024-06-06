/* Program to calculate the nth fibonacci term using iteration */

#include <stdio.h>

// Function prototype declaration
int fibo (int);

int main(){
	int n, f;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	f  = fibo(n);
	
	printf("The fibonacci sequence nth term is: %d", f);
	
	return 0;
}

int fibo (int x){
	int fibonacci;
	
	if(x == 0){
		return 0;
	} else if(x == 1){
		return 1;
	} else if( x > 1){
		return fibonacci = fibo(x - 1) + fibo(x - 2);
	}
}

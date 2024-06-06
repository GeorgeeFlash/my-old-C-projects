#include <stdio.h>

int factor (int);

int main(){
	int x, fact;
	
	printf("Enter num: ");
	scanf("%d", &x);
	
	fact = factor(x);
	
	printf("Factorial of %d = %d", x, fact);
	
	return 0;
}

int factor (int x){
	int factorial;
	
	if(x == 0){
		return 1;
	} else if(x > 0){
		return factorial = x * factor(x - 1);
	}
}

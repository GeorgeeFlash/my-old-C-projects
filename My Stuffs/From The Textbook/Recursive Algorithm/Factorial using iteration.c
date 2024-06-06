#include <stdio.h>

int factor (int);

int main() {
	int n, fact;
	
	printf("Enter num: ");
	scanf("%d", &n);
	
	fact = factor(n);
	
	printf("Factorial of %d = %d", n, fact);
	
	return 0;
}

int factor (int x){
	int y = 1;
	
	for(int i = 1; i <= x; i++){
		y *= i;
	}
	
	return y;
}

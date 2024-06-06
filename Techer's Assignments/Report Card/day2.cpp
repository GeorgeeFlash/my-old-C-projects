#include<stdio.h>
int main(){
	int i, number, factorial = 1;
	printf("enter a number: ");
	scanf("%d", &number);
	for(i = 1; i <= number; i ++){
		factorial = factorial * i;
	}
	printf("%d! = %d\n", number, factorial);
}

#include <stdio.h>
#include <stdlib.h>

// This procedure is for converting the temperature from Fahrenheit to Celsius
float calc(float);

int main()
{
	float Df = 0; // Df is for the degrees in Fahrenheit
	
	printf("Enter the temperature in Fahrenheit: ");
	scanf("%f", &Df);

	float Dc = calc(Df);
	printf("\nThe Temperature in Celsius is: %.2f^C\n", Dc);
	
	return 0;
}
float calc(float F)
{
	return (F - 32)*5/9;	
}
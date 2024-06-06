#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*A program for calculating the roots of a quadratic equation*/
int main() 
{
	float a, b, c;
	float x1, x2;
	
	printf("Enter a: ");
	scanf("%f", &a);
	printf("Enter b: ");
	scanf("%f", &b);
	printf("Enter c: ");
	scanf("%f", &c);
	
	x1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
	x2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);
	
	// Root is for finding out if the roots are Real or Equal
	float root = pow(b,2)-4*a*c;
			
	if(root > 0)
	{
		printf("Real roots: x1 = %.1f and x2 = %.1f\n", x1, x2);
	}
	else if(root < 0)
	{
	//real and im are for the roots of a cmplex equation
	float real = -b/(2*a);
	float im = sqrt(-(pow(b,2) - 4*a*c))/(2*a);
	
		printf("Complex roots: x1 = %.1f+%.1fi and x2 = %.1f-%.1fi\n", real, im, real, im);
	}
	else if(root == 0)
	{
		printf("Equal roots: x1 = x2 = %.1f", x1);
	}
	
	return 0;
}
#include <stdio.h>

int main()
{
	// constant = fixed value that cannot be altered by the program during compilation
	
	const float PI = 3.14159;
	
	printf("Original value of PI: %f\n", PI);
//	printf("Enter new value of PI: ");
//	scanf("%f", &PI); // The value of PI can be changed by scanf at runtime.
//	
//	
//	float area = PI * 10 * 10; // calculating the area of a circle with radius 10 after modifying PI during runtime.
//	printf("\nArea of circle =  %.2f m^2", area);
	
	PI = 4.135; // The value of PI cannot be modified, as this will result in an error.
	
	printf("\nNew value of PI is %.2f", PI);
	
	return 0;
}

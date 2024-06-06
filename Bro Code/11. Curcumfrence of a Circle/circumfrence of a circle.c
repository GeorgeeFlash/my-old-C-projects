#include <stdio.h>

int main()
{
	const double PI = 3.14159;
	double radius;
	double circumfrence;
	double area;
	
	printf("\nEnter the radius of a circle: ");
	scanf("%lf", &radius);
	
	circumfrence = 2 * PI * radius;
	area = PI * radius * radius;
	
	printf("\nArea: %lf", area);
	printf("\nCircumfrence: %lf", circumfrence);
	
	return 0; 
}

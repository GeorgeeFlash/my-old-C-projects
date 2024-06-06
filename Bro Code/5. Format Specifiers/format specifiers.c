#include <stdio.h>

int main()
{
	// format specifier % = defines and formats a type of data to be displayed
	
	// %c = character
	// %s = string (array of characters)
	// %f = float
	// %lf = double
	// %d = integer
	
	//%.1 = decimal precision
	// %1 = minimal field width
	// %- = left align
	
	float item1 = 5.75; 
	float item2 = 10.00;
	float item3 = 100.99;

//	float student1 = 3.78;
//	float student2 = 3.42;
//	float student3 = 3.00;
//	
//	printf("Student 1 = %f\n", student1);
//	printf("Student 2 = %f\n", student2);
//	printf("Student 3 = %f\n", student3);
	
	printf("Item 1: $%8.2f\n", item1);
	printf("Item 2: $%8.2f\n", item2);
	printf("Item 3: $%-8.2f\n", item3);

//	char c = 'C';
//
//	printf("This is %c", c);
	
	return 0;
}

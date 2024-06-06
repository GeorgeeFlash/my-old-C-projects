#include <stdio.h>

int main()
{
	/* variable = Allocated space in memory to store a value.
				  We refer to a variable's name to access the stored value.
				  That varable now behaves as if it was the value it contains.
				  BUT we need to declare what type of data we are storing.
	*/
	
	int x; //declaration
	x = 123; // initialization
	int y = 593; // declaration + initialization
	
	int age = 15; 				// Make sure variable name is descriptive
	float gpa = 4.0; 			// floating point number
	char grade = 'C'; 			//single character
	char name[] = "Georgee"; 	//array of characters

	printf("Hello %s\n", name); // % is a format specifier
	printf("You are %d years old\n", age);
	printf("Your average grade is %c", grade);
	printf("Your gpa is %f", gpa);
	return 0;
}

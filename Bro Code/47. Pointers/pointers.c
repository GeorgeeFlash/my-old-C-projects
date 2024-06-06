#include <stdio.h>

int main()
{
	// pointer = a "variable-like" reference that holds a memory address to another variable, array, etc
	//			 some tasks are perfomed more easily with pointers
	//			 * = indirection operator (value at address)
	
	/* Advantages of Using Pointers
		- Less time in program execution.
		- Working on the original variable.
		- With the help of pointers, we can create data structures (linked-list, stack, queue).
		- Returning more than one values from function.
		- Searching more than one values from function.
		- Dynamically memory allocation.
	*/
	
	int age = 15;
	int *pAge = &age;
	
	printf("Address of age: %p\n", &age);
	printf("Value of pAge: %p\n", pAge);
	
	printf("Size of age: %d bytes\n", sizeof(age));
	printf("Size of pAge: %d bytes\n", sizeof(pAge));
	
	printf("Value of age: %d\n", age);
	printf("Value at stored adddress: %d\n", *pAge); //dereferencing
	
	
	
	return 0;
}

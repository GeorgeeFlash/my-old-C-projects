#include <stdio.h>

int main()
{
	// memory = an array of bytes within RAM (street)
	// memory block = a single unit (byte) within memory, used to hold some value (person)
	// memory address =  the address of where a memory block is located (house address)
	
//	char a = 'X';
//	char b = 'Y';
//	char c = 'Z';
	
	short int a = 1;
	int b = 2;
	int c = 3;
	float d = 4.3;
	
	printf("%d bytes\n", sizeof(a));
	printf("%d bytes\n", sizeof(b));
	printf("%d bytes\n", sizeof(c));
	printf("%d bytes\n", sizeof(d));
	
	
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//	printf("%p\n", &c);
	
	
	return 0;
}

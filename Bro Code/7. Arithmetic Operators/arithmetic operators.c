#include <stdio.h>

int main()
{
	//arithmetic operators
	
	// + (addition)
	// - (subtraction)
	// * (multiplication)
	// / (division)
	// % (modulus)
	// ++ increment
	// -- decrement
	
	int x = 5;
	int y = 2;
	
//	x++; // same as x = x + 1
//	y++; // same as y = y + 1
//
//	printf("%d\n", x);
//	printf("%d", y);

//	x--; // x = x - 1
//	y--; // y = y - 1
//
//	printf("%d\n", x);
//	printf("%d", y);
	
//	int z = x % y;
//	printf("%d", z);
	
	float z = x / (float) y; // You have to precede the divisor or dividend by a float or double since you can't divide an int by int 
							 // else you will have your decimal portion of the answer truncated (i.e., you will get 2.00...
							 // instead of 2.5000...
							 // or you simply change your initial variable to a float
	
	printf("%.2f", z);
	
	return 0;
}

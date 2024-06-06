#include <stdio.h>
#include <string.h>

int main()
{
//	char x = 'X';
//	char y = 'Y';
//	char temp;
//	
//	temp = x;
//	x = y;
//	y = temp;

	char x[15] = "water";
	char y[15] = "lemonade";
	char temp[15];
	
	// Remember to give sizes if you wish to swap strings in order to avoid strange behaviour
	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
	
	printf("x = %s\n", x);
	printf("y = %s\n", y);
	
	return 0;
}

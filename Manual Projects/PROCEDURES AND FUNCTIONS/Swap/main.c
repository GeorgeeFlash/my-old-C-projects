#include <stdio.h>
#include <string.h>

int main()
{
	char x[5];
	char y[5];
	char temp[5];

	
	printf("Enter first parameter: ");
	scanf("%s", &x);
	printf("Enter second parameter: ");
	scanf("%s", &y);
		
	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
	
	printf("Swapping these values would give: %s, %s.", x, y);
	
	
	return 0;
}
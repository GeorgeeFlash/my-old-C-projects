#include <stdio.h>

int main()
{
	int x;
	int y;
	
	printf("Enter first parameter: ");
	scanf("%d", &x);
	printf("Enter second parameter: ");
	scanf("%d", &y);
	
	int temp = x;
	x = y;
	y = temp;
	
	printf("Switching these values will give: %d, %d. \n", x, y);
	
	
	return 0;
}
#include <stdio.h>

int main(void)
{
	int i, space, rows, k = 0;
	printf("enter rows: ");
	scanf("%d", &rows);
	for(i = 1; i <= rows; i ++, k = 0)
	{
		for(space = 1; space <= rows - i; space ++)
		{
			printf(" ");
		}
		while(k != 2 * i  - 1)
		{
			k ++;
			printf("%d", i);
		}
		printf("\n");
	}
	
 return 0;
}

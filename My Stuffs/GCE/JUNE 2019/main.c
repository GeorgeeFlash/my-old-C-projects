#include <stdio.h>
#include <stdlib.h>

//Global variables
int size = 5;


int fillRowFoward(int[size][size], int, int, int, int);
int fillColumnDownwards(int[size][size], int, int, int, int);
int fillRowBackwards(int[size][size], int, int, int, int);
int fillcolumnUpwards(int[size][size], int, int, int, int);

int main()
{
	int num = 1;
	int N = size - 1;
	int array[size][size];
	int i = 0, j = 0;
	int top = 0, left = 0, right = 4, bottom = 4;
	
	/*for(k = 0; k < size; k++)
	{
		for(l = 0; l < size; l++)
		{
			array[k][l] = num;
			num++;
		}
	}*/
	while(i < (N/2))
	{
		fillRowFoward(array, top, left, right, num);
		top++;
		fillColumnDownwards(array, top, right, bottom, num);
		right--;
		fillRowBackwards(array, bottom, left, right, num);
		bottom--;
		fillcolumnUpwards(array, bottom, top, left, num);
		left++;
		i++;
	}
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%-5d", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	
	
	
	return 0;
}
//Functions for filling array in spiral order 
int fillRowFoward(int array[size][size], int top, int left, int right, int num)
{
	for(left; left <= right; left ++, num++)
	{
		array[top][left] = num;
	}
	return num;
}
int fillColumnDownwards(int  array[size][size], int top, int right, int bottom, int num)
{
	for(top; top <= bottom; top++, num++)
	{
		array[top][right] = num;
	}
	return num;
}
int fillRowBackwards(int array[size][size], int bottom, int left, int right, int num)
{
	for(right; right >= left; right--, num++)
	{
		array[bottom][right] = num;
	}
	return num;
}
int fillcolumnUpwards(int array[size][size], int bottom, int top, int left, int num)
{
	for(bottom; bottom >= top; bottom--, num++)
	{
		array[bottom][left] = num;
	}
	return num;
}


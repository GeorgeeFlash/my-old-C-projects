#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int size = 6;
	int arr[6][6];
	int N = size - 1;
	int num = 1;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < size/2; i++, N--)
	{
			//left to right
		for(j = i; j <= N; j++, num++)
		{
			arr[i][j] = num;
		}
		
		//top to bottom
		for(j = i + 1; j <= N; j++, num++)
		{
			arr[j][N] = num;
		}
		
		//right to left
		for(j = N - 1; j >= i; j--, num++)
		{
			arr[N][j] = num;
		}
		
		//bottom to top
		for(j = N - 1; j > i; j--, num++)
		{
			arr[j][i] = num;
		}
	}

	
	//display spiral square from 2D array
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

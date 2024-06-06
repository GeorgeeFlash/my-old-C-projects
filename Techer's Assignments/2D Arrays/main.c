#include <stdio.h>
#include <stdlib.h>

void sumArray();


/*To take in the array size from the user, set maybe array like array[row][column].
The the idea i had for taking in the array for a particular size(say 100) as the 
limit, use an if statement*/
int main()
{
	int array1[100][100];
	int array2[100][100];

	
	int row1= sizeof(array1)/sizeof(array1[0]);
	int column1= sizeof(array1[0])/sizeof(array1[0][0]);
	
	int row2 = sizeof(array2)/sizeof(array2[0]);
	int column2 = sizeof(array2[0])/sizeof(array2[0][0]);
	
	printf("Enter First array:\n");
	
	for(int i=0; i<row1; i++)
	{
		printf("{");
		for(int j=0; j<column1; j++)
		{
			scanf("%d ", &array1[i][j]);
		}
		printf("}");
		printf("\n\n");
	}
	
	printf("\nEnter Second array:\n");
	
	for(int i=0; i<row2; i++)
	{
		printf("{");
		for(int j=0; j<column2; j++)
		{
			scanf("%d ", &array2[i][j]);
		}
		printf("}");
		printf("\n");
	}
	
	printf("\n\n");
	sumArray(array1, array2, row1, column1, row2, column2);

	
	return 0;
}

void sumArray(int array1[2][2], int array2[2][2])
{
	int sum[100][100];
	int row = sizeof(sum)/sizeof(sum[0]);
	int column = sizeof(sum[0])/sizeof(sum[0][0]);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			sum[i][j] = array1[i][j]+array2[i][j];
		}
	}
	
	printf("Sum = \n");
	for(int i=0; i< row; i++)
	{
		printf("{");
		for(int j=0; j< column; j++)
		{
			printf("%.2d ", sum[i][j]);
		}
		printf("}");
		printf("\n");
	}
	
}




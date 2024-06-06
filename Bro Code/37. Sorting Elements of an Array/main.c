#include <stdio.h>

void sort(char array[], int size)
{
	for(int i = 0; i < size - i - 1; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp; 
			}
		}
	}
}

void printArray(char Array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%c\t", Array[i]);
	}
}

int main()
{
//	int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
	char array[] = {'F', 'A', 'D', 'B', 'C', 'E'};
	int b = 10;
	
	int size = sizeof(array)/sizeof(array[0]);
	
	sort(array, size);
	printArray(array, size);
		
	return 0;
}

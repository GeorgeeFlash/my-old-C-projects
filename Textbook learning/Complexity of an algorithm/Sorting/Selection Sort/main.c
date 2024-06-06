// Program for selection sort
#include <stdio.h>

int main()
{
	int array[100], size, i, j, swap, min;
	
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);
	
	printf("Enter the elements of the array: \n");
	for(i = 0; i < size; i++)
		scanf("%d", &array[i]);
	
	for(i = 0; i < (size-1); i++)
	{
		min = i;
		for(j = i + 1; j < size; j++)
		{
			if(array[j] < array[min])
			min = j;
		}
		if(min != i)
		{
			swap = array[i];
			array[i] = array[min];
			array[min] = swap;
		}
	}
	printf("Sorted list in ascending order: ");
	for(i = 0; i < size; i++)
		printf("%d ", array[i]);
	
	return 0;
}

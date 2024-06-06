// Example: Program for Bubble Sort
#include <stdio.h>

void bubbleSort(int[], int);

int main()
{
	int array[100], n, i;
	
	printf("Enter the number of items in the array: ");
	scanf("%d", &n);
	
	printf("Enter the array elements: \n");
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	bubbleSort(array, n);
	
	printf("Array in sorted order: ");
	for(i=0; i<n; i++)
	{
		printf("%d ", array[i]);
	}
	
	return 0;
}
void bubbleSort(int list[], int size)
{
	int i, j, temp;
	
	for(i=0; i < size-1; i++)
	{
		for(j=0; j < size-i-1; j++)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}


/* C implementation Quick sort */
#include <stdio.h>
#include <conio.h>

// quick sort function to sort integer array list
void quicksort(int array[], int firstIndex, int lastIndex)
{
	//declaring index variables
	int pivotIndex, temp, index1, index2;
	if(firstIndex < lastIndex)
	{
		//assignment fisrt element index as pivot element
		pivotIndex = firstIndex;
		index1 = firstIndex;
		index2 = lastIndex;
		//sorting in ascending order with quick sort
		while(index1 < index2)
		{
			while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
			{
				index1++;
			}
			while(array[index2]>array[pivotIndex])
			{
				index2--;
			}
			if(index1<index2)
			{
				//swapping operation
				temp = array[index1];
				array[index1] = array[index2];
				array[index2] = temp;
			}
		}
		//At the end of first iteration, swap pivot element with index2 element
		temp = array[pivotIndex];
		array[pivotIndex] = array[index2];
		array[index2] = temp;
		//Recursive call for quick sort, with partitioning
		quicksort(array, firstIndex, index2 - 1);
		quicksort(array, index2 + 1, lastIndex);
	}
}
int main()
{
	//Declaring variables
	int array[100], n, i;
	//Number of elements in an array form user input
	printf("Enter the number of elements you want to Sort: ");
	scanf("%d", &n);
	//code to ask to enter elements from user equal to n
	printf("Enter Elements in the list: \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	//calling quicksort function define defined above
	quicksort(array, 0, n-1);
	//print sorted array
	printf("Sorted elements: ");
	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	getch();
	
	return 0;
}

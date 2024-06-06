#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int randomize();
void print();
int linearSearch(int[], int, int);
void selectionSort(int[], int);
void selectionSortDecreasing(int[], int);
void replaceFirst(int[], int, int, int);
int replaceAll(int[], int, int, int, int);
int binarySearch(int[], int, int);
void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);

void main() 
{
	int list[100], i, j, n;
	
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	printf("Enter the array elements:\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
	
	//linearSearch(list, 5, n);
	//replaceAll(list, 5, 5, 10, n);
	//replaceFirst(list, 5, 10, n);
	//selectionSort(list, n);
	//printf("\nNow in Decreasing order, we have: \n");
	//selectionSortDecreasing(list, n);
	//binarySearch(list, 5, n);
	//bubbleSort(list, n);
	//insertionSort(list, n);
	quickSort(list, 0, n-1);
	
	for(i = 0; i < n; i++)
	{
		printf("\n%d\t", list[i]);
	}
	
	
	//return 0;
}
int randomize()
{
	int list[100], i;
	srand(time(0));
	for(i = 0; i < 100; i++)
	{
		int random = (rand() % 100) + 1;
		list[i] = random;
	}
	return list[100];
}
void print(int array[100])
{
	for(int i=0; i<sizeof(array)/sizeof(array[0]); i++)
	{
		printf("%d\n", array[i]);
	}
}
int linearSearch(int list[100], int target, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(list[i] == target)
		{
			//printf("%d was found at index %d\n", target, i + 1);
			return i + 1;
		}
	}
	if(i == n)
	{
		//printf("%d was not found in the list\n", target);
		return -1;
	}
}
void selectionSort(int array[100], int n)
{
	int position, swap, i, j;
	
	for(i = 0; i < (n-1); i++)
	{
	position = i;
	for(j = i + 1; j < n; j++)
	{
		if(array[position] > array[j])
		{
			position = j;
		}
	}
	if(position != i)
	{
		swap = array[i];
		array[i] = array[position];
		array[position] = swap;
	}
	}
	printf("Sorted list in ascending order:\n");
	for(i = 0; i < n; i++)
	printf("%d\n", array[i]);
}
//Selection sort for decreasing order
void selectionSortDecreasing(int array[100], int n)
{
	int position, swap, i, j;
	
	for(i = 0; i < (n-1); i++)
	{
		position = i;
		for(j = i + 1; j < n; j++)
		{
			if(array[position] < array[j])
			{
				position = j;
			}
		}
		if(position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
		}
	}
	printf("Sorted list in ascending order:\n");
	for(i = 0; i < n; i++)
	printf("%d\n", array[i]);
}
void replaceFirst(int list[100], int oldVal, int newVal, int n)
{
	int response = linearSearch(list, oldVal, n);
	if(response != -1)
	{
		list[response - 1] = newVal;
	}	
}

//Procedure for searching all the indexes for the value searched
int replaceAll(int list[100], int target, int oldVal, int newVal, int n)
{
	int i = 0, j =  0;
	for(i = 0; i < n; i++)
	{
		if(list[i] == target)
		{
			list[i] = newVal;
			j ++;
		}
	}
	return j;
}
int binarySearch(int list[100], int target, int n)
{
	int f = 0;
	int l = n - 1;
	int m = (f + l) / 2;
	
	while(f <= l)
	{
		if(list[m] < target)
			f = m + 1;
		else if(list[m] == target)
			return m + 1;
		else
			l = m - 1;
		m = (f + l)/2;
	}
	if(f > l)
		return -1;
}
void bubbleSort(int list[100], int n)
{
	int i, j, temp;
	for(i = 0; i < n - i  - 1; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}
void insertionSort(int list[], int n)
{
	int key, i, temp;
	for(i = 1; i <= n - 1; i++)
	{
		key = i;
		while(key > 0 && list[key] < list[key - 1])
		{
			temp = list[key];
			list[key] = list[key - 1];
			list[key - 1] = temp;
			key --;
		}
	}
}
void quickSort(int array[], int firstIndex, int lastIndex)
{
	//declearing index variables
	int pivotIndex, temp, index1, index2;
	if(firstIndex < lastIndex)
	{
		//assighning first element index as pivot
		pivotIndex = firstIndex;
		index1 = firstIndex;
		index2 = lastIndex;
		//Sorting in Ascending order with quick sort
		while(index1 < index2)
		{
			while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
			{
				index1++;
			}
			while(array[index2] > array[pivotIndex])
			{
				index2--;
			}
			if(index1 < index2)
			{
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
		quickSort(array, firstIndex, index2 - 1);
		quickSort(array, index2 + 1, lastIndex);
	}
}


/* 
* This is a program that generates random numbers btw 1 and 10 and determines
  the repeating numbers as well as the number of times they repeat
*	
* File: main.c
*
*/	

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void bubblesort(int[], int);
void duplicates(int[], int[], int[], int);
void arrayElements(int[], int);

int i, j, k = 0;


int main()
{
	// The size of the array is taken from the user
	int size;
	
	printf("Enter size of the array: ");
	scanf("%d",&size);
	
	int A[size];
	int found[k];
	int numOfTimes[k];

	arrayElements(A, size);
	bubblesort(A,size);
	printf("\n*************************\n");
	printf("Elements of array: ");
	for(i = 0; i < size; i++)
	{
		printf("%d, ", A[i]);
	}
	printf("\n*************************\n");
	
	duplicates(A, found, numOfTimes, size);
	
//	int sizeOfFound = sizeof(found)/sizeof(found[0]);
//	int sizeOfnumOfTimes = sizeof(numOfTimes)/sizeof(numOfTimes[0]);
	
//	printf("Size of found: %d, Size of numOfTimes: %d\n", sizeOfFound, sizeOfnumOfTimes);
	
	printf("\n*************************\n");
	printf("Duplicated elements: ");
	for(i = 0; i < k; i++)
	{
		printf("%d, ", found[i]);
	}
	printf("\n*************************\n");
	
	printf("\n*************************\n");
	printf("Number of times repeated(respectively): ");
	for(i = 0; i < k; i++)
	{
		printf("%d, ", numOfTimes[i]);
	}
	printf("\n*************************\n");
	
	return 0;
}

void arrayElements(int A[], int size)
{
	printf("Ener elements into array\n");
	for(i=0;i<size-1;i++)
	{
		scanf("%d",&A[i]);
	}
	srand(time(0));
	int element;
	for(i = 0; i < size; i++)
	{
		element = (rand() % 10) + 1;
		A[i] = element;
	}
}

void bubblesort(int A[],int size)
{
	for(i = 0; i < size - 1; i++)
	{
		for(j = 0; j < size - 1; j++)
		{
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	
}
void duplicates(int A[], int found[], int numOfTimes[], int size)
{
	int count;
	bool foundIt;
	
	for(i = 0; i < size - 1; i++)
	{
		foundIt = false;
		count = 1;
		
		if(A[i] == 0)
		{
			continue;
		}
		for(j = i + 1; j < size; j++)
		{
			if(A[i] == A[j] && A[j] != 0)
			{
				count++;
				A[j] = 0;
				foundIt = true;
			}
		}
		if(foundIt == true)
		{
			found[k] = A[i];	
			numOfTimes[k] = count; 
			k++;
		}
	}
}

/** Program for quick sort **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int array[], int firstIndex, int lastIndex){
	
	// declaring first element index as pivot element
	int pivotIndex, temp, index1, index2;
	if(firstIndex < lastIndex){
		// assigning first element index as pivot element.
		pivotIndex = firstIndex;
		index1 = firstIndex;
		index2 = lastIndex;
		
		// Sorting in ascending order with quick sort
		while(index1 < index2){
			while(array[index1] <= array[pivotIndex] && index1 < lastIndex){
				index1++;
			}
			while(array[index2] > array[pivotIndex]){
				index2 --;
			}
			if(index1 < index2){
				temp = array[index1];
				array[index1] = array[index2];
				array[index2] = temp;
			}
		}
		
		// At the end of first iteration, swap pivot element with index2 element
		temp = array[pivotIndex];
		array[pivotIndex] = array[index2];
		array[index2] = temp;
		// Recursive call for quick sort, with partitioning
		quicksort(array, firstIndex, index2 - 1);
		quicksort(array, index2 + 1, lastIndex);
	}
}

int main(){
	int n;
	
	// Seed to generate random numbers
	srand(time(0));
		
	printf("Enter size of array: ");
	scanf("%d", &n);
	
	int arr[n];
	
	/** Filling array with random numbers from 1 to 100 **/
	for(int i = 0; i < n; i ++){
		arr[i] = ((rand() % 100) + 1);
	}
	
	/* QuickSort */
	quicksort(arr, 0, n-1);
	
	printf("Sorted array: ");
	for(int i = 0; i < n; i++){
		printf(" %d", arr[i]);
	}
	
	return 0;
}

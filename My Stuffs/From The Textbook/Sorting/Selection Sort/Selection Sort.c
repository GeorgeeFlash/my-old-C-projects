/** Program for selection sort **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n, swap, start;
	
	// Seed to generate random numbers
	srand(time(0));
		
	printf("Enter size of array < 100: ");
	scanf("%d", &n);
	
	int arr[n];
	
	/** Filling array with random numbers from 1 to 100 **/
	for(int i = 0; i < n; i ++){
		arr[i] = ((rand() % 100) + 1);
	}
	
	/** Selection sort algorithm **/
	for(int i = 0; i < n-1; i++){
		start = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[start])
				start = j;
		}
		if(start != i){
			swap = arr[i];
			arr[i] = arr[start];
			arr[start] = swap;
		}
	}
	
	printf("Sorted array: ");
	for(int i = 0; i < n; i++){
		printf(" %d", arr[i]);
	}
	
	return 0;
}

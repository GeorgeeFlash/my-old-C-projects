/** Program for Insertion sort **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
	/* Insertion Sort */
	for(int i = 1; i < n; i++){
		int j = i;
		while(j > 0 && arr[j] <  arr[j-1]){
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
	
	printf("Sorted array: ");
	for(int i = 0; i < n; i++){
		printf(" %d", arr[i]);
	}
	
	return 0;
}

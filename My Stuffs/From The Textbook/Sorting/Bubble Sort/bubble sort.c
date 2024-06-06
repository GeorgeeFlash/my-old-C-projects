/** Program for bubble sort **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int[], int);

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
	
	bubble_sort(arr, n);
	
	printf("Sorted array: ");
	for(int i = 0; i < n; i++){
		printf(" %d", arr[i]);
	}
	
	return 0;
}

void bubble_sort(int list[], int n){
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(list[j] > list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}

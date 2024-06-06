/** Program for sequential search
 ** The program generates random numbers from 1 - 100 for a given user input
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// Seed to generate random numbers
	srand(time(0));
	
	int n, search, cnt;
	
	printf("Enter size of array < 100: ");
	scanf("%d", &n);
	
	int arr[n];
	
	/** Filling array with random numbers from 1 to 100 **/
	for(int i = 0; i < n; i ++){
		arr[i] = ((rand() % 100) + 1);
	}
	
	printf("Array: ");
	for(int i = 0; i < n; i++){
		printf(" %d", arr[i]);
	}
	
	/** Sequencial Search algorithm **/
	system("cls");
	printf("Enter the number to search: ");
	scanf("%d", &search);
	
	for(cnt = 0; cnt < n; cnt++){
		if(arr[cnt] == search){ /* if required element is found */
			printf("%d is present at location %d.\n", search, cnt + 1);
			return 0;
		}
	}
	printf("%d is not present in array.\n", search);
	
	return 0;
}

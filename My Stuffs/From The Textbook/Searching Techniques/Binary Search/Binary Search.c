/** Program for binary search **/

#include <stdio.h>

int main(){
	int f, l, m, size, sElement;
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	size = sizeof(list)/sizeof(list[0]);
	
	printf("Enter value to be searched: ");
	scanf("%d", &sElement);
	
	f = 0;
	l = size - 1;
	m = (f + l)/2;
	
	while (f <= l) {
		if (list[m] < sElement)
			f = m + 1;
		else if (list[m] == sElement){
			printf("Element found at index %d.\n", m);
			return 0;
		}
		else
			l = m - 1;
		m = (f + l)/2;
	}
	printf("Element not found in the list.");
	
	return 0;
}

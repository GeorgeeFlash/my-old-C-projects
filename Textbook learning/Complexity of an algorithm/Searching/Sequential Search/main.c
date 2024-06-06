/** Example: Program for Binary Search **/
#include <stdio.h>
#include <conio.h>

int main()
{
	int f, l, m, i,  sElement, list[50], size;
	
	printf("Enter the number of elements in the array: ");
	scanf("%d", &size);
	
	printf("Enter the elements of the array: \n");
	for(i=0; i<size; i++)
		scanf("%d", &list[i]);
		
	printf("Enter the element you wish to search: ");
	scanf("%d", &sElement);
		
	f = 0;
	l = size - 1;
	m = (f + l)/2;
	
	while(f <= l)
	{
		if(list[m] < sElement)
			f = m + 1;
		else if(list[m] == sElement)
		{
			printf("%d was found at position %d\n", sElement, m+1);
			break;
		}
		else
			l = m - 1;
			m = (f + l)/2;
	}
	if(f > l)
		printf("%d was not found in the list!\n", sElement);
	getch();
	
	return 0;
}

#include <stdio.h>

void main()
{
	int heap[10], no, i, j, c, root, temp;
	printf("\nEnter no of elements: ");
	scanf("%d", &no);
	printf("\nEnter the nos: ");
	for(i=0; i<no; i++)
		scanf("%d", &heap[i]);
	for(i=1; i<no; i++)
	{
		c = i;
		do
		{
			root = (c-1)/2;
			if(heap[root] < heap[c])	/* to create MAX heap array*/
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while(c != 0);
	}
	printf("Heap array: ");
	for(i=0; i<no; i++)
	printf("%d\t", heap[i]);
	for(j = no-1; j >=0; j--)
	{
		temp = heap[0];
		heap[0] = heap[j];	/*swap max element with rightmost leaf element */
		heap[j] = temp;
		root = 0;
		do
		{
			c = 2 * root  + 1;	//left node of root element
			if(heap[c] < heap[c+1])
		}
	}
	
}

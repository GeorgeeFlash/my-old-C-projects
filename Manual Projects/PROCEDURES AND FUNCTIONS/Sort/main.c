#include <stdio.h>

void sort(int No1, int No2);
int main()
{
	int No1 = 5, No2 = 3;
	
	sort(No1,No2);	
	
	return 0;
}
void sort(int No1, int No2)
{
	if(No1 > No2)
	{
		int temp = No1;
		No1 = No2;
		No2 = temp;
	}
	printf("Sorting gives: %d, %d\n", No1, No2);

}

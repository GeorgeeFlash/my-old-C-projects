#include <stdio.h>
#include <stdlib.h>

void ranking(float gloavr[], int soga);
void printRank(float gloavr[], int soga);

int main()
{
	int num;
	int numFlag= 0;
	int numSubs;
	int index = 1;
	printf("Enter the number of students: ");
	scanf("%d", &num);
	
	float gloavr[num];
	int cfga = 0;// Count for gloavr(Class averages)
	int soga = sizeof(gloavr)/sizeof(gloavr[0]);// Size of global average or class average
	do
	{
		int markFlag = 1;
		float marks[numSubs];
		float sum = 0;
		float peravr;
		int cfpa = 0;//count for peravr(personal average)
		printf("\n------------------------------------------");
		printf("\nEnter number of subjects for student %d: ", index);
		scanf("%d", &numSubs);
			
		for(int i=0; i<numSubs; i++)
		{
			printf("Mark %d: ", markFlag);
			scanf("%f", &marks[i]);
			markFlag++;		
		}
			
		for(int cfpa=0; cfpa<numSubs; cfpa++)
		{
			sum+=marks[cfpa];
		}
		peravr =  sum/numSubs;
		printf("This students Average = %.2f", peravr);
		printf("\n*****************************\n");
		
		gloavr[cfga] = peravr;
		cfga++; 
		
		index ++;
		numFlag++;
	}while(numFlag<num);
	printf("------------------------------------------");

	
	printf("\nTotal averages: ");
	for(int k=0; k<num; k++)
	{
		printf("%.2f\t", gloavr[k]);
	}
	
	ranking(gloavr, soga);
	printRank(gloavr, soga);
	
	return 0;
}

void ranking(float gloavr[], int soga)
{
	for(int l=0; l<soga-l-1; l++)
	{
		for(int m=0; m<soga-1; m++)
		{
			if(gloavr[m]<gloavr[m+1])
			{
				int temp = gloavr[m];
				gloavr[m] = gloavr[m+1];
				gloavr[m+1] = temp;
			} 
		}
	}	
}

void printRank(float gloavr[], int soga)
{
	int counting = 1;
	printf("\n\nANNUAL RANKING\n");	
	printf("----------------------------------------------");
	for(int i=0; i<soga; i++)
	{
		printf("\nThe %dth position has an Average of %.2f\n", counting, gloavr[i]);
		counting++;
	}
	printf("\n----------------------------------------------");

	printf("\n");
}

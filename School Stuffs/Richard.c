#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
	int Sn;
	int hashcode;
	int average;
} StudInfo;

void hash(int);
void initStudInfo();
void studHash();
void studResultInfo(int[2][5]);

int hashCode[5], result[2][5];

StudInfo student1;
StudInfo student2;
StudInfo student3;
StudInfo student4;
StudInfo student5;

// Array was assumed to have one element so i used a size of 5 instead
StudInfo studResult[5];

int main()
{	
	hash(20);
	
	initStudInfo();
	studHash();
	studResultInfo(result);
	
	printf("\n************************************************\n");
	for(int i = 0; i < sizeof(result)/sizeof(result[0]); i++){
		if(i == 0){
			printf("Average:\t");
		} else{
			printf("Hashcode:\t");
		}
		printf("|");
		for(int j = 0; j < sizeof(result[0])/sizeof(result[0][0]); j++){
			printf(" %d |", result[i][j]);
		}
		printf("\n");
	}
	printf("\n************************************************\n");

	
	return 0;
}

// create unique hash codes for students
void hash(int N){
	bool exist; 
	int r, count = 0;
	
	srand(time(0));
	
	while(count < 5)
	{
		exist = 0;
		r = (rand() % ( (N+11)-11+1 )) + 11;
		

		if(r % 2 != 0)
		{
			for(int i = 0; i < count; i++){
				if(r == hashCode[i]){
					exist = 1;
					break;
				}
			}
			if(exist == 0){
				hashCode[count] = r;
				count ++;
			}
		}
	}
}

// enter Sn and average for each student
void initStudInfo(){
	for(int i = 0; i < 5; i++){
		printf("\nEnter Sn: ");
		scanf("%d", &studResult[i].Sn);
		printf("\nEnter Average:");
		scanf("%d", &studResult[i].average);
	}
}

// assign each student a hash code
void studHash(){	
	for(int i = 0; i < 5; i++){
		studResult[i].hashcode = hashCode[i];
	}
}

// Extract student results and average and store in array Result
void studResultInfo(int A[2][5]){	
	for(int i = 0; i < 5; i++){
		A[0][i] = studResult[i].average;
		A[1][i] = studResult[i].hashcode;
	}
}

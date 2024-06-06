#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	int index = 1, n, m, i, j, k;
	int selectedDays[7];	//This variable is for the selected days the user will enter in order to print out the days the user wants
	char subjects[50][20];
	char name[25];
	char day[20][10] = {"Monday  ", "Tuesday  ", "Wednesday", "Thursday", "Friday  ", "Saturday", "Sunday  "};
	
	printf("Enter your name: ");
	fgets(name, 25, stdin);
	name[strlen(name) - 1] = '\0';
	
	printf("How many subjects do you have per day?: ");
	scanf("%d", &n);
	fgetc(stdin);
	
	printf("How many days do you go to school per week?: ");
	scanf("%d", &m);
	fgetc(stdin);
	
	printf("Please enter the days you go to school per week. IN ORDER!\n");
	printf("Enter:\n(0) for Mon\n(1) for Tues\n(2) for Wed\n(3) for Thur\n(4) for Fri\n(5) for Sat\n(6) for Sun\n");
	for(i = 0; i < m; i++)
	{
		scanf("%d", &selectedDays[i]);
	}
	fgetc(stdin);
	
	//this for loop takes in the subjects the user has per day daily
	k = n;	//This value is to be used to take in the subjects so that the value of n remains unchanged
	for(i = 0; i < m; i++)
	{
		printf("\nEnter the subjects for day%d: \n", index);
		for(j = (i * n); j < k; j++)
		{
			scanf("%s", &subjects[j]);
		}
		k += n;
		index ++;
	}
	
	printf("\n\nSubjects: ");
	for(i = 0; i < (n * m); i++)
	{
		printf("%s  ", subjects[i]);
	}
	printf("\n\n");
	
	printf("\n\t\t\t\t====*%s's TIME TABLE*====\n\n", name);
	
	//printing the periods
	index = 1;
	printf("DAY\t\t");
	for(i=0; i<n; i++)
	{
		printf("Period%d\t\t", index);
		index ++;
	}
	
	//Printing the timetable showing the days and subjects as well, first loop for day and next loop for subject
	printf("\n\n");
	for(i = 0; i < m; i++)
	{
		printf("%s\t", day[selectedDays[i]]);
		for(j = i * n; j < (n * i) + n; j++)
		{
			printf("%s\t\t", subjects[j]);
		}
		printf("\n\n");
	}
	
	
	return 0;
}

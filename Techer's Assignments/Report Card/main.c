#include<stdio.h>
int main() {
	float salary, percentage, percentage2, salary2, salary3;
	char g;
	printf("enter the salary of the employee: \n");
	scanf("%f", &salary);
	printf("enter the gender of the employee: \n");
	scanf(" %s", &g);
	switch(g){
		case 'f':
				percentage = salary * 0.1;
				salary2  = salary + percentage;
			if(salary2 < 10000){
				percentage2 = salary * 0.02;
				salary3  = salary2 + percentage2;
				printf("this employee is getting %.1f\n", salary3);
			} else {
				printf("this employee is getting %f\n", salary2);
			}
		case 'm':
			percentage = salary * 0.05;
			salary2 = salary + percentage;
			printf("this employee if getting %.1f\n", salary2);

	}			
}

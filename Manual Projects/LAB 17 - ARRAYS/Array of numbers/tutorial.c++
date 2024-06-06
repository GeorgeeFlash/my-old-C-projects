#include<stdio.h>
#include<windows.h>
int main(){
	int tempareture;
	printf("enter a temp: \n");
	scanf("%d",&tempareture);
	if(tempareture > 30){
		printf("it is hot outside\n");
	}
	else if(temparature < 0){
		printf("it is cold outside\n");
	}
	else{
		printf("it is warm out side\n");
	}
}

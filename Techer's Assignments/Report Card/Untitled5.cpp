#include<stdio.h>
int main(){
	int passward = 1234;
	int pass;
	printf("enter your password: ");
	scanf("%d", &pass);
	
		if(pass != passward){
			for(int i = 0; i <= 3; i ++){
				printf("enter your passward\n");
			}
		}
}

#include <stdio.h>
#include <string.h>

int main()
{
	int age;
	char name[25]; //bytes
	
	printf("What's your name? ");
	//scanf("%s", &name);
	fgets(name, 25, stdin);
	name[strlen(name)-1] = '\0';
	
	printf("How old are you? ");
	scanf("%d", &age);
	
	printf("\nHello %s, how are you?", name);
	printf("\nYou are %d years old.", age);
	
	return 0;
}

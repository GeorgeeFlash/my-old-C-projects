#include <stdio.h>

//typedef char user[25]

typedef struct
{
	char name[25];
	char password[12];
	int id;	
} User;

int main()
{
	// typedef = reserved keyword that gives an exsisting datatype a "nickname"
	
	User user1 = {"Georgee", "1309r3rj", 1849879234};
	User user2 = {"Tee", "13294p3rj", 384294724};
	
//	user user1 = "Georgee";

	printf("%s\n", user1.name);
	printf("%s\n", user1.password);
	printf("%d\n", user1.id);
	
	printf("\n\n");
	
	printf("%s\n", user2.name);
	printf("%s\n", user2.password);
	printf("%d\n", user2.id);
	
	
	return 0;
}

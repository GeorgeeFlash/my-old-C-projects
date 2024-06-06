#include <stdio.h>

enum Day{Sun = 1, Mon = 2, Tues = 3, Wed = 4, Thurs = 5, Fri = 6, Sat = 7
};

int main()
{
	//enum = a user defined type of named integer identifiers
	//		 helps to make a program more readable
	
	enum Day today = Sun;
	
	//printf("%d", today); //enums are NOT STRINGS, bu they can be treated a int
	
	if(today == Sun || today == Sat)
	{
		printf("It's the weekend! Party time!");
	}
	else
	{
		printf("I have to work today!\n");
	}
	
	return 0;
}

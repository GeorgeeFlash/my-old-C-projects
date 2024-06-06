#include <stdio.h>

int main()
{
	FILE *pF = fopen("C:\\Users\\FF-TECHNO\\Desktop\\test.txt", "w");
	
	fprintf(pF, "\nPatrick Star");
	
	fclose(pF);

//	if(remove("test.txt") == 0)
//	{
//		printf("That file was deleted successfully!");
//	}
//	else
//	{
//		printf("That file was NOT deleted!");
//	}
	
	
	return 0;
}

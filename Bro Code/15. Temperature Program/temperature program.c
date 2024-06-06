#include <stdio.h>
#include <ctype.h>

int main()
{
	char unit;
	float temp;
	
	printf("\nIs the temperature in (F) or (C)? ");
	scanf("%c", &unit);
	
	unit = toupper(unit);
	
	if(unit == 'C'){
		printf("\nEnter the temp in Celsuis: ");
		scanf("%f", &temp);
		temp = (temp * 9/5) + 32;
		printf("The temp in Farenheiht is: %.1f", temp);
	}
	else if(unit == 'F'){
		printf("\nEnter the temp in Farenheiht: ");
		scanf("%f", &temp);
		temp = ((temp - 32) * 5) / 9;
		printf("The temp in Celsius is: %.1f", temp);
	}
	else{
		printf("%s is not a valid unit of measurement!\n", unit);
	}
	
	return 0;
}

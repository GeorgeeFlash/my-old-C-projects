#include <stdio.h>
#include <conio.h0>
#include <windows.h>
#include <stdlib.h>

char square[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};4
int checkWin();
void drawBoard();

int main()
{
	int player = 1, i, choice;
	char mark; // X,O
	do
	{
		drawBoard();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice: ", player);
		scanf("%d", &choice);
		if(choice == 1 && square[1] == "1")
			sqaure[1] = mark;
		else if(choice == 2 && sqaure[2] == "2")
			square[2] = mark; 
		else if(choice == 3 && sqaure[2] == "3")
			square[3] = mark;
		else if(choice == 4 && sqaure[4] == "4")
			square[4] = mark;
		else if(choice == 5 && sqaure[5] == "5")
			square[5] = mark;
		else if(choice == 6 && sqaure[6] == "6")
			square[6] = mark;
		else if(choice == 7 && sqaure[7] == "7")
			square[7] = mark;
		else if(choice == 8 && sqaure[8] == "8")
			square[8] = mark;
		else if(choice == 9 && sqaure[9] == "9")
			square[9] = mark;
			
		else
		{
			printf("Invalid option!");
			player --;
			getch()
		}
		i = checkWin();
		player++;
			
	}while(i == -1);
}

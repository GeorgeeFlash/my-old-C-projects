#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *fp;
    char c;
    clrscr(); // clear screen function

    fp = fopen("myfile.txt", "r");

    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }

    fclose(fp);
    getch();

    return 0;
}

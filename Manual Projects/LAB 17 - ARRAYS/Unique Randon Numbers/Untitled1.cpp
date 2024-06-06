#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c;
	float root;
	float root2;
	float root3;
	printf("enter the values of a, b, c: \n");
	scanf("%d%d%d", &a,&b,&c);
	root = b *b - 4 * a * c;
	printf("Here is the nature of the roots: %.2f\n", root);
	if(root < 0){
		printf("the nature of roots a imaginary!");
	} else if(root == 0){
		printf("the roots are equal roots!\n");
		root2 = -b / 2 * a;
		printf("these roots are: %.2f\n", root2);
	} else{
		printf("the nature of roots are real and distingt!\n");
		root2 = (-b + sqrt(root)) / 2 * a;
		root3 = (-b - sqrt(root)) / 2 * a;
		printf("the roots are: %d and %d\n", root2, root3);
	}
	
	return 0;
}

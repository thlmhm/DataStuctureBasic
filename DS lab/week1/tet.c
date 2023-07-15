#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(int argc, char *argv[])
{
	
	if(argc != 4)
	{
		printf("SYNTAX ERROR!\n PLEASE ENTER AGAIN : <name> <a> <b> <c>\n");
		return 1;
	}
	
	float a,b,c;
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	
	float delta;
	delta = b*b - 4*a*c;
	float can;
	can = sqrt(delta);
	if(delta == 0)
	{
		printf("The equation has unique solution.\n");
		printf("x1 = x2 = %.2f\n", -b/(2*a));
	}
	else if(delta > 0)
	{
		printf("The equation has two different solution.\n");
		printf("x1 = %.2f\n", (-b + can)/(2*a));
		printf("x2 = %.2f\n", (-b - can)/(2*a));
	}
	else
	{
		printf("The equation has no solution\n");
	}
	return 0;
	
}

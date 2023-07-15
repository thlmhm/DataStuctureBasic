#include<stdio.h>
#include<string.h>
#define size 100
char *findfname(char *a)
{
	int i;
	for(i=strlen(a)-1; i>=0;i--)
	{
		if(a[i]==' ') break;
	}
	return a + i + 1;
}
/*
void swap(char *a, char *b){
    char c;
    c = *a;
    *a = *b;
    *b = c;
}
*/
int main()
{
	int num=0,i,j;
	printf("Enter the number of students in a class:");	
	scanf("%d", &num);
	while(getchar() != '\n');
	
	char name[num][size];
	char fname[num][size];
	for (i = 0; i<num ; i++)
	{
		printf("Enter the name of student %d :", i+1);
		gets(name[i]);
		strcpy(findfname(name[i]), fname[i]);
	}
	char swap[size];
	for( i = 0; i < num - 1 ; i++)
	{
	    for( j = 0; j < num - 1; j++)
		{
            if (strcmp(fname[j],fname[j+1]) > 0)
            {
            	strcpy(swap, fname[j]);
				strcpy(fname[j], fname[j+1]);
				strcpy(fname[j+1], swap);	
			}               
        }
	}
	for( i = 0; i < num; i++)
	{
		printf("%s\n", name[i]);
	}
	int check = 0, max = 0;
	for( i = 0; i < num -1; i++)
	{
		for ( j = 0; i <num -1; j++)
		{
			if(strcmp(fname[j],fname[j+1]) == 0)
			{
				check ++;
			}
		}
		if(check > max) max = check;
	}
	printf("Maximum number of students having the same first name : %d\n", max);
	
}

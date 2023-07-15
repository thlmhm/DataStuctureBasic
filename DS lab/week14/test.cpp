#include<stdio.h>

int main()
{
	
	int x,y,t=0;
	for(x = 1;x <=10 ; x++ )
	{
		for(y=1;y<=10;++y)
		{
			if(x==y){
			t+=x*y;}
		}
	}
	printf("%d", t);
}

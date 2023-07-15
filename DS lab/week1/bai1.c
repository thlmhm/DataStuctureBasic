
#include<stdio.h>
#define N 3

int comp(int a1[], int a2[], int num)
{
	int i;
	for(i=0; i<num;i++)
	{
		if(a1[i] == a2[i])
		return 1;
		if(a1[i]+a2[i] == 0)
		return -1;				
	}
	return 0;
	
}

int main()
{
	int a1[N], a2[N];
	int i;
	int result;
	printf("Enter array number 1:\n");
	for(i=0; i<N;i++)
	{
		printf("a1[%d] = ",i);
		scanf("%d", &a1[i]);		
	}
	printf("Enter array number 2:\n");
	for(i=0; i<N;i++)
	{
		printf("a2[%d] = ",i);
		scanf("%d", &a2[i]);		
	}
	result = comp(a1,a2,N);
	switch(result)
	{
		case 1: 
			printf("Two arrays are equal.");
			break;
		case -1: 
			printf("Two arrays are symmetric.");
			break;
		default:
			printf("No identical");
			break;			
	}
	
}

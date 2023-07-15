#include<stdio.h>
int binsearch(int low,int high,int s[],int key)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(key==s[mid]) return mid;
		else if(key<s[mid])
		return binsearch(low,mid-1,s,key);
		else return binsearch(mid+1,high,s,key);
		}
	else return -1;
	}
int main()
{
	int s[15]={6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
	int key,k;
	printf("Enter the value of key: ");
	scanf("%d",&key);
	k = binsearch(0,14,s,key);
	if(k==-1) printf("Key is not found !\n");
	else printf("The index of %d in array is %d\n",key,k);
	return 0;
}
/*
In the case key = 31:
mid = 7;
s[7] = 53 > 31 

binsearch(0,6,s,31)
mid = 3
s[3] = 25 < 31

binsearch(4,6,s,31)
mid = 5;
s[5] = 43 > 31

binsearch(4,4,s,31)
mid = 4;
s[4] = 33 != 31

return -1

In main function print Key is not found


*/

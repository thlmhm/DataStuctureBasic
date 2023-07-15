#include<iostream>
using namespace std;
int main()
{
	int n,i,j,dem=0;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
	  cin>>a[i];
	int b[n],c[n],d[n];

	for (i=0;i<n;i++)
	{
		
		b[i]=1;
	    for(j=0;j<i;j++)
	      if((a[j]<a[i])&&(b[i]<b[j]+1)) b[i]=b[j]+1;
	    c[i]=b[i]-1;
    }
	int maxx=b[0],k=0;
	for (i=0;i<n;i++)
	  if (b[i]>maxx)
	    {
	    	maxx=b[i];
	    	k=i;
		}
	cout<<maxx<<endl;
	d[dem]=a[k];
	while (c[k]>0)
	  {
	  	for (int i=0;i<k;i++)
	  	  if ((b[i]==c[k])&&(a[i]<a[k]))
	  	  {
	  	    dem+=1;
	  	    d[dem]=a[i];
	  	    k=i;
	  	    break;
	      }
	  }
	for (int j=dem;j>=0;j--)
	  cout<<d[j]<<"  ";
	return 0;
	
}

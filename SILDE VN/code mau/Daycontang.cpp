#include<iostream>
using namespace std;
int main()
{
	int a[30001];
	int b[30001];
	int c[30001];
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i,j,jmax;
	a[0]=INT_MIN; a[n+1]=INT_MAX;
	b[n+1]=1;
	for (i=n;i>=0;i--)
	{
	   jmax=n+1;
	   for (j=i+1;j<=n+1;j++)
	      {
	      	if (a[j]>a[i]&&b[j]>b[jmax])
	      	    jmax=j;
		  }
	   b[i]=b[jmax]+1;
	   c[i]=jmax;
    }
	int k=c[0];
	while (k!=n+1)
	   {
	   	  cout<<a[k]<<"    ";
	   	  k=c[k];
	   }
	 return 0;		
}


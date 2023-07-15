#include <iostream>
using namespace std;
int n, m, count;
int a[100];
bool candidate(int j, int k)
{
	int i;
	for (i=1; i<=k-1; i++)	
	if (j == a[i])
	return false;
	return true;
}
int PrintSolution() {
	int i, j;
	count++;
	cout<<"Permutation #"<<count<<": ";
	for (i=1 ; i<= n ;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
void Try(int k)
{
	int j;
	for (j = 1; j<=n; j++)
	if (candidate(j,k)){ 	
		a[k] = j;
		if (k==n) PrintSolution( );
		else Try(k+1);
	}
}
int main() {
	cout<<("Enter n = "); cin>>n;
	count = 0; Try(1);
	cout<<"Number of permutations = " << count;
}

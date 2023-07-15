#include<iostream>
using namespace std;
#define MAXN 20
int a[MAXN], s[MAXN] ,n,count;

void print_str(){
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	count++;
}

void backtrack(){
    int k = 1; s[k] = 0;
    while (k > 0){
        while ( s[k] <= 1 )
        {
            a[k] = s[k];
            s[k] += 1;
            if (k == n) print_str();
           else {k++ ;
                s[k] = 0;
        }
    }
    k--;
  }
}


int main()
{
	cout<<"n= "; cin>>n;
	count = 0;
	backtrack();
	cout<<"Number of  binary string: "<<count;
	return 0;
}

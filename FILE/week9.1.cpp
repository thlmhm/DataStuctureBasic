#include<bits/stdc++.h>
using namespace std;
int n;
int F1(int n)
{
	if(n<2) return n;
	else {
		return F1(n-1)+F1(n-2);
	}
}
int F2(int n)
{
	int x,y,z;
	x=0;
	y=1;
	//z = x+y;
	for(int k = 2; k<=n; k++){
		z = x +y;
		x = y; 
		y = z;
		//z = x + y;
	}
	return z;
}
int main(){
	n = 5;
	cout<<"Recusive = "<<F1(n)<<endl;
	cout<<"Non-Recusive = "<<F2(n)<<endl;
}

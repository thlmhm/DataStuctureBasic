#include<iostream>
#include<queue>
using namespace std;
int listSize;
int helperSum(int list[], int i){
	
	if( i == 0)
		return list[i];
	else
		return list[i]+helperSum(list,i-1);
}

int main(){
	int list[5] ={1,2,3,4,5};
	listSize =5;
	int KQ= helperSum(list,5);
	cout<<"KQ = "<<KQ<< endl;
}

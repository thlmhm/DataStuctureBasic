#include<iostream>
#include<queue>
using namespace std;
int listSize;
/*
int prod(int list){
	return helperProd(list,0);
}
*/
int helperProd(int list[],int i){
	if(i==listSize-1)
		return list[i];
	else
		return list[i]*helperProd(list,i+1);
}
int main(){
	int list[5] ={1,2,3,4,5};
	listSize =5;
	int KQ= helperProd(list,0);
	cout<<"KQ = "<<KQ<<endl;
}

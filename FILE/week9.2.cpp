#include<bits/stdc++.h>
using namespace std;
int Palindrome(string str,int start, int end){
	if(start >= end) return 1;
	else 
		if(str[start] != str[end]) return 0;
		else return Palindrome(str,start+1, end-1);
}
int main(){
	string str = "MOOM";
	int result = Palindrome(str,0, str.length() -1);
	if(result == 1) cout<<"It is palindrome"<<endl;
	else cout<<"Not"<<endl;
}

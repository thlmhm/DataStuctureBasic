#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
stack <int> s1;
stack <int> s2;
void pushstack(string in1, string in2){
	int num1 = in1.length();
	int num2 = in2.length();
	for(int i = 0; i<num1;i++)
		s1.push(in1[i] - 48);
	for(int j = 0; j<num2;j++)
		s2.push(in2[j] - 48);
}
*/
void sum(char* str1, char* str2, int size1,int size2){
	stack <int> S1,S2,S;
	for(int i = 0; i<size1; i++)
		S1.push(str1[i] - 48);
	for(int j = 0; j<size2; j++)
		S2.push(str2[j] - 48);
	
	int carry = 0,a,b,c;
	while(S1.empty() == 0 || S2.empty() == 0){
		if(S1.empty() == 0){		
			a = S1.top();S1.pop();
		}
		else if(S2.empty() == 0){		
			b = S2.top();S2.pop();
		}
		else b = 0;
		c = a+b+carry;
		carry = c/10; 
		S.push(c%10);
	}
	cout<<a<<" " <<b<<endl; 
	if(carry != 0) S.push(carry);
	cout<<"Ket qua =";
	while(S.empty() == 0)
	{
		cout<<S.top();
		S.pop();
	}

}
int main()
{
	char* in1;
	char* in2;
	/*cout<<"Enter number 1 "<<endl;
	getline(cin,in1);
	cout<<"Enter number 2 "<<endl;
	getline(cin,in2);
	*/
	sum("12345", "12345", 5,5);
}

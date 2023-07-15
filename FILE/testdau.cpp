#include<stack>
#include<iostream>
using namespace std;
bool isPair(char open,char close)
{
	if(open == '(' && close ==')') return 1;
	if(open == '(' && close ==')') return 1;
	if(open == '(' && close ==')') return 1;
	return 0;
}
bool checking(char*str, int size)
{
	stack <char> S;
	for(int i =0;i<size; i++)
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			S.push(str[i]);
		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			char current = S.top();
			S.pop();
			if(isPair(current,str[i]) == 0) return 0;
		}
	if(S.empty()==0) return 0;
	return 1;
}

int main()
{
	bool ok = checking("{}}{})(())",10);
	if(ok == 1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

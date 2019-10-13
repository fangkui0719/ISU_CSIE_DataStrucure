#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

int main ()
{
	string infix,prefix;
	char ch,ch1; //ch:判斷輸入算式中字元為符號還是字母(數字), ch1:要放入stack的符號 
	stack<char> s; 
	cout << "輸入算式(Infix)：";
	getline(cin,infix);
	cout << "Infix:" << infix << endl;
	
	for(int i=infix.length()-1;i>=0;i--)
	{
		ch=infix[i];
		if(isalnum(ch)) prefix+=ch; //isalnum:可判斷字元是符號還是字母(數字) 
		else if(ch=='(')
		{
			while(s.top()!=')')
			{
				ch1=s.top();
				s.pop();
				prefix+=ch1;
			}
			ch1=s.top();
			s.pop();
		} 
		else if(ch=='+'||ch=='-')
		{
			while(!s.empty()&&(s.top()=='*'||s.top()=='/'))
			{
				ch1=s.top();
				s.pop();
				prefix+=ch1;
			}
			s.push(ch);
		}
		else
		{
			s.push(ch);
		}
	}
	
	while(!s.empty())
	{
		ch1=s.top();
		s.pop();
		prefix+=ch1;
	}
	
	cout << "Prefix:";
	for (int i=prefix.length()-1;i>=0;i--)
	{
		cout << prefix[i];
	}
	cout << endl;
	
	system("pause");
	return 0;	 
}

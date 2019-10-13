#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

int main ()
{
	string infix,prefix;
	char ch,ch1; //ch:�P�_��J�⦡���r�����Ÿ��٬O�r��(�Ʀr), ch1:�n��Jstack���Ÿ� 
	stack<char> s; 
	cout << "��J�⦡(Infix)�G";
	getline(cin,infix);
	cout << "Infix:" << infix << endl;
	
	for(int i=infix.length()-1;i>=0;i--)
	{
		ch=infix[i];
		if(isalnum(ch)) prefix+=ch; //isalnum:�i�P�_�r���O�Ÿ��٬O�r��(�Ʀr) 
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

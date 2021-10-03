#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void calculate(stack<double> &num, stack<char> &ch)
{
	double a = num.top();
	num.pop();
	double b = num.top();
	num.pop();
	char c = ch.top();
	ch.pop();

	switch(c)
	{
		case '+': num.push(b+a); break;
		case '-': num.push(b-a); break;
		case '*': num.push(b*a); break;
		case '/': num.push(b/a); break;
	}
}

int pre(char c)
{
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else 
		return 0;
}

int main()
{
	stack<double> num;
	stack<char> ch;
	string s;

	while(cin>>s)
	{
		if(s=="=")	break;

		int n = s.size();
		
		for (int i = 0; i < n; ++i)
		{
			if(isdigit(s[i])) //判断该字符是否是十进制数字
			{

				double tmp = atof(&s[i]);
				num.push(tmp);
				while(isdigit(s[i]) || s[i]=='.') i++;  //跳到最后
				i--;
			} 
			else {
				if(ch.empty())
					ch.push(s[i]);
				else if(s[i]=='(')
					ch.push(s[i]);
				else if(s[i]==')')
				{
					while(ch.top()!='(')
						calculate(num, ch);  //不到左括号就一直计算
					ch.pop();
				}
				else if(pre(s[i]) > pre(ch.top()))
					ch.push(s[i]);
				else if(pre(s[i]) < pre(ch.top()))
				{
					while(!ch.empty() && pre(s[i])<=pre(ch.top()))
						calculate(num, ch);
					ch.push(s[i]);
				}
			}	
		}

		cout << fixed << setprecision(2) << num.top() << endl;
		num.pop();
		ch.pop();
	}
	
	return 0;
}
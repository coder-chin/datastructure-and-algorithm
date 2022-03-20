#include <iostream>
#include <stack>
#include <string>
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
			if(s[i] >= '0' && s[i] <= '9')
			{
				double tmp = s[i] - '0';
				i++;
				while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!=')' && s[i]!='=')
				{
					//cout << s[i] << endl;
					if(s[i] >= '0' && s[i] <= '9') {
						tmp = 10*tmp + (s[i]-'0');
						i++;
					}
					else if(s[i]=='.') {
						int e = 0;
						i++;
						double dot = 0;
						
						while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!=')' && s[i]!='=') {
							e++;
							dot = s[i] - '0';
							for (int j = 0; j < e; ++j)
							{
								 dot /= 10;
							}
							tmp += dot;
							i++;
						}
					}
				}
				num.push(tmp);
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
						calculate(num, ch);  
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

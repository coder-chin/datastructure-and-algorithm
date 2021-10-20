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
		case '+': num.push(b+a); break;    // 注意 a 和 b 的顺序
		case '-': num.push(b-a); break;
		case '*': num.push(b*a); break;
		case '/': num.push(b/a); break;
	}
}

// 比较优先级
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
	stack<double> num;  // 存放数字
	stack<char> ch;		// 存放运算符
	string s;           // 表达式

	while(cin>>s)
	{
		if(s=="=")	break;

		int n = s.size();
		
		for (int i = 0; i < n; ++i)
		{
			if(s[i] >= '0' && s[i] <= '9')  // 是数字
			{
				double tmp = s[i] - '0';
				i++;
				while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!=')' && s[i]!='=')
				{
					//cout << s[i] << endl;
					if(s[i] >= '0' && s[i] <= '9') {
						tmp = 10*tmp + (s[i]-'0');
						i++; //�����������ƶ� 
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
						calculate(num, ch);  //不到左括号就一直计算
					ch.pop();    			// 左括号走人
				}
				else if(pre(s[i]) > pre(ch.top()))
					ch.push(s[i]);           // 优先级高压入
				else if(pre(s[i]) < pre(ch.top()))
				{
					while(!ch.empty() && pre(s[i])<=pre(ch.top()))
						calculate(num, ch);   //优先级低就一直计算
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

#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
// https://www.cnblogs.com/suchang/p/10547671.html  getline输入整行

void calculate(stack<double> &sta, char ch)
{
	double a = sta.top();
	sta.pop();
	double b = sta.top();
	sta.pop();

	if(ch=='+')
		sta.push(b+a);
	else if(ch=='-')
		sta.push(b-a);
	else if(ch=='*')
		sta.push(b*a);
	else if(ch=='/')
		sta.push(b/a);
}

int main()
{
	string s;

	while(getline(cin, s))
	{
		if(s=="=")
			break;

		stack<double> sta;

		int n = s.size();

		for (int i = 0; i < n; ++i)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				int dot = 0;  //整数和小数部分次幂
				double tmp = s[i]-'0';
				i++;
				while(s[i]!=' ' && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
				{
					// 整数
					if(s[i]>='0' && s[i]<='9') {
						tmp = 10*tmp+s[i]-'0';
						i++;
					}
					// 小数
					else if(s[i]=='.')
					{
						i++;
						double afterDot = 0;
						while(s[i]!=' ' && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
						{
							dot++;
							afterDot = s[i]-'0';
							for (int i = 0; i < dot; ++i)
								afterDot/=10;
							tmp += afterDot;
							i++;
						}
					}
				}
				//cout << tmp << endl;
				i--;
				sta.push(tmp);
			}

			
			else if(s[i]==' ')
				continue;

			else if(s[i]=='=')
				break;

			else
				calculate(sta, s[i]);
		}
		cout << fixed << setprecision(2) << sta.top() << endl;

	}

	return 0;
}
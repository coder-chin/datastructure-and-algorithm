#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string s;
	while(cin >> s)
	{
		int flag = 1;
		if(s=="0")
			break;

		stack<char> re;  //存储逆转序列
		int n = s.size(); //s大小

		for (int i = 0; i < n; ++i)
			re.push(s[i]); //逐个入栈

		for (int i = 0; i < n; ++i)
		{
			if(re.top()!=s[i])
			{
				flag = 0;
				break;
			}
			else 
				re.pop();
		}
		
		if(flag)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	
	return 0;
}
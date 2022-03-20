#include <iostream>
#include <string>
#include <stack>
using namespace std;

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
	string s, ret;         //s是原始 ret是结果
	    // 存符号
	char tmp;

	

	while(cin>>s && s!="=")
	{	
		stack<char> symbol;
		ret = "";
		for (unsigned int i = 0; i < s.size(); ++i)
		{
			 if(s[i]>='0' && s[i]<='9')
			 {
			 	ret += s[i];
			 }

			 	

			 else {
			 	if(symbol.empty() || s[i]=='(' || s[i]=='*' || s[i]=='/')
			 		symbol.push(s[i]);

			 	else if(s[i]==')') {
			 		while(symbol.top()!='(') {
			 			tmp = symbol.top();
			 			ret += tmp;
			 			symbol.pop();
			 		}
			 		symbol.pop(); 
			 	}

			 	else if(pre(s[i]) <= pre(symbol.top())) {
			 		while(!symbol.empty() && pre(s[i]) <= pre(symbol.top())) {
			 			tmp = symbol.top();
			 			ret += tmp;
			 			symbol.pop();
			 		}
			 		symbol.push(s[i]);
			 	}

			 	else // 前面是(的加或减
			 		symbol.push(s[i]);
	
			 }
		}

		cout << ret << endl;
	}
	return 0;
}

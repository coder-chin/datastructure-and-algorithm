#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	int flag;

	while(cin>>s && s!="0")
	{		
		stack<char> sta;
		flag = 1;

		for (unsigned int i = 0; i < s.size(); ++i)
		{
			if(sta.empty())  //空的
			{
				if(s[i]=='I')  //I压入
					sta.push(s[i]);
				else
				{       //O完蛋
					flag = 0;
					break;
				}
			}

			else if((s[i]=='O'&&sta.top()=='I'))
				sta.pop();   // 配对完美

			else 
				sta.push(s[i]);
		}

		if(sta.empty() && flag)
			cout << "TRUE" << endl;
		else 
			cout << "FALSE" << endl;
 	}
 	return 0;
}
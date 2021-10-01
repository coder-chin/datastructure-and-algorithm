#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="=")	break;

		int n = s.size();
		cout << n;
	}
	
	return 0;
}
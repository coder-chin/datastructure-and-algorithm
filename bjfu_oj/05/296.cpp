#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map(char ch) {
	if(ch=='B')
		return 3;
	else if(ch=='W')
		return 2;
	else 
		return 1;
}

string swapSort(string s) {
	int n = s.size();
	int flag;
	char ch;
	int i, j;

	for (i = 0; i < n-1 ; ++i)
	{
		ch = s[i];
		flag = i;
		for (j = i+1; j < n; ++j) 
		{
			if(map(s[j])<map(ch)) {
				ch = s[j];
				flag = j;
			}
		}
		swap(s[i], s[flag]);
	}
		
	return s;
}

int main()
{
	int n;
	char ch;

	while(cin>>n && n) {
		string s = "";
		while(n--) {
			cin >> ch;
			s += ch;
		}

		string ret = swapSort(s);

		int n = ret.size();
		
		for (int i = 0; i < n-1; ++i)
		{
			cout << ret[i] << " ";
		}
		cout << ret[n-1] << endl;
	}

	return 0;
}

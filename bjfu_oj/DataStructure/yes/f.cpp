#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int num, n, k, K;
	string s;

	cin >> num;

	while(num--)
	{
		k = 0;
		cin >> n >> K;
		cin >> s;

		string tmp(s.rbegin(), s.rend());

		int cnt = s.size();
		for (int i = 0; i < cnt; ++i)
		{
			if(s[i]!=tmp[i])
				k++;  // 实际k
		}

		if(k<=K)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}
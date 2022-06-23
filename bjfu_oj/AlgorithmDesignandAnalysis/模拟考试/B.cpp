#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, length;
	cin >> t;
	string str;

	while(t--) {
		cin >> length;
		cin >> str;

		for (unsigned int i = 0; i < str.length(); ++i) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				str[i] -= 32;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32;
			}
		}
		cout << str << endl;
	}
	return 0;
}

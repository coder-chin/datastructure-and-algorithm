#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, len1, len2;
	string s1, s2;

	cin >> T;

	while(T--) {
		cin >> len1 >> len2;
		cin >> s1;
		cin >> s2;

		int times = 0;

		for(int i = 0; i < len1; i++) {
			bool flag = true;
			for(int j = 0; j < len2; j++) {
				if(s2[j] != s1[i+j]) {
					flag = false;
					break;
				}
			}
			if(flag) times++;
		}

		cout << times << endl;
	}

	return 0;
}
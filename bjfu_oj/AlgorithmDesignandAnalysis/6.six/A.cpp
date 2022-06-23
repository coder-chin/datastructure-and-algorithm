#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	char add, del, rep1, rep2;
	int a, b, c;
	string tmp, sub;
	int i = 1;

	while(cin >> s) {
		cin >> add >> a;  // 添加字母
		cin >> del;
		cin >> rep1 >> rep2;
		cin >> b >> c;
		cin >> sub;

		cout << "Case " << i << ":" << endl;

		s = s.substr(0, a) + add + s.substr(a);
		cout << "Insert->" << s << endl;

		string::iterator it;     //指向string类的迭代器。你可以理解为指针

		for (it = s.begin(); it != s.end(); it++) {
			if (*it == del) {
				s.erase(it);
				it--;
			}
		}

		cout << "Erase->" << s << endl;

		replace(s.begin(), s.end(), rep1, rep2);
		cout << "Replace->" << s << endl;

		cout << "Size->" << s.size() << endl;

		tmp = s;
		reverse(tmp.begin(), tmp.end());
		cout << "Reverse->" << tmp << endl;

		cout << "Sub->" << s.substr(b, c-b+1) << endl;
		
		int res = -1;
		if(s.find(sub) < s.size()) {
			res = s.find(sub);
		}
		
		cout << "Find->" << res << endl << endl;

		i++;
	}

	return 0;
}

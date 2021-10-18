#include <iostream>
#include <string>
using namespace std;

bool matchString(string s1, string s2) {
	int m = 0;
	int n = 0;
	int len1 = s1.size(); 
	int len2 = s2.size();

	while(m<len1 && n<len2) {
		if(s1[m] == s2[n]) {
			m++;
			n++;
		} else {
			n = n-m+1;
			m = 0;
		}
	}

	if(m==len1) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	string s1;
	string s2;
	bool flag;
	string tmp;
	int length;

	while(cin >> s1 >> s2) {
		if(s1=="0" && s2=="0") 
			break;
		
		string s3 = s1+s1;
		// cout << "s3: " << s3 << endl;
		
		length = s1.length();
		// cout << length << endl;

		for(int i=0; i<length; i++) {
			tmp = s3.substr(i, length);
			// cout << tmp << endl;
			flag = matchString(tmp, s2);
			if(flag) 
				break;
		}

		if(flag) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;

	}
	return 0;
}
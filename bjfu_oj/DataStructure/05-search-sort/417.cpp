#include <iostream>
#include <string>
using namespace std;

void strstr(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	int i = 0, j = 0, start = 0;

	while(i<n1 && j<n2) {
		if(s1[i] == s2[j]) {
			i++;
			j++;
		} else {
			i = i-j+1;
			j = 0;
			start = i;
		}
	}

	if(j==n2) {
		cout << start << endl;
	} else {
		cout << -1 << endl;
	}
}

int main()
{
	string s1, s2;

	while(cin>>s1>>s2 && s1!="0" && s2!="0") {
		strstr(s1, s2);
	}
}
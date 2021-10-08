#include <iostream>
#include <string>
using namespace std;

string insert(string s, string t, int pos) {
	int preLenght = s.length();
	
	s += t;
	
	int length = t.length(); 
	
	for (int i = preLenght-1; i >= pos-1; i--) {
		s[i+length] = s[i];
	}  //?? 

	for (unsigned int i = 0; i < t.length(); ++i) {
		s[pos-1+i] = t[i];
	}  //??? 
	
	return s;
}

int main() 
{
	int pos;
	string s1, s2;

	while(cin>>pos && pos) {
		cin >> s1 >> s2;

		s1 = insert(s1, s2, pos);

		cout << s1 << endl;
	}
}

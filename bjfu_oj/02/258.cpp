#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
	if(s.length()==1) {
		return s;
	} 
	return reverse(s.substr(1)) + s[0];
}

int main() 
{
	string str;

	while(cin>>str && str!="0") {
		str = reverse(str);
		cout << str << endl;
	}
	
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	
	char ch;

	while(cin>>s && s!="0") {
		vector<int> fre(36, 0); //frequency
		for (unsigned int i = 0; i < s.length(); ++i) {
			if(s[i]>='0' && s[i]<='9') {
				fre[s[i]-'0'] ++;
			} else if(s[i]>='A' && s[i]<='Z') {
				fre[s[i]-55] ++;
			}
		}

		for (unsigned int i = 0; i < fre.size(); ++i) {
			if(fre[i]) {
				if(i<10) {
					ch = i+'0';
					printf("%c:%d\n", ch, fre[i]);
				} else {
					ch = i+'A'-10;
					printf("%c:%d\n", ch, fre[i]);
				}
			}
		}
	}

	

	return 0;
}

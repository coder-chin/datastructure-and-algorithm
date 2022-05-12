#include <iostream>
#include <string>
using namespace std;
// 消除相同连续字符
int main()
{
	string str;

	while(cin >> str) {
		int length = str.length();
		if(length == 0) {
			cout << "" << endl;
		}
		// 双指针
		int left = 0, right = 1;
		
		while(right < length) {
			if(str[left] == str[right]) right++;
			else {
				left++;
				str[left] = str[right];
			}
		}
		
		for (int i = 0; i <= left; ++i)
			cout << str[i];
		cout << endl;
	}
}
#include <iostream>
#include <string>
using namespace std;

string push(string words)
{
	string str;
	cin >> str;
	words+=str;   //string 直接拼
	return words;
}
string cut(string words)
{
	int loc, length;
	cin >> loc >> length;

	return words = words.substr(loc, length);  //函数见名知意，截取字符串
}
string insert(string words)
{
	int index;
	string part;
	cin >> index >> part;
	words += part;

	int n1 = words.size(), n2 = part.size();

	for (int i = n1-1; i >= index; i--)
	{
		words[i+n2] = words[i];
	} //后移
	for (int i = 0; i < n2; ++i)
	{
		words[index+i] = part[i];
	} //插入

	return words;
}
void findIndex(string words)
{
	string tmp;
	cin >> tmp;

	if(words.find(tmp) < words.size()) 
		cout << words.find(tmp) << endl;

	else cout << -1;
}
int main()
{
	int times, choice;
	string words(100, 0);

	cin >> times >> words;

	while(times--)
	{
		cin >> choice;
		switch(choice) {
			case 1:
				words = push(words);
				cout << words << endl;
				break;

			case 2:
				words = cut(words);
				cout << words << endl;
				break;

			case 3:
				words = insert(words);
				cout << words << endl;
				break;

			case 4:
				findIndex(words);
		}
	}

	return 0;
}
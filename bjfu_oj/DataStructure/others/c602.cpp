#include <iostream>
#include <vector>
using namespace std;
// 是4的倍数且不是100的倍数 或者 是400的倍数

int main()
{
	int x, y;
	vector<int> ret;

	cin >> x >> y;
	for (int i = x; i <= y; i++)
	{
		if((i%4==0&&i%100!=0) || i%400==0)
		{
			ret.push_back(i);
		}
	}

	cout << ret.size() << endl;

	for (unsigned int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}

	return 0;
}
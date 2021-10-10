#include <iostream>
#include <vector>
using namespace std;
// 数组的主元素：出现次数大于n/2
int main()
{
	int n, tmp;

	while(cin>>n &&n) {
		vector<int> v;
		vector<int> ret(10, 0);
		int flag = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 0; i < n; ++i)
		{
			ret[v[i]] ++;
		}

		for (int i = 0; i < 10; ++i)
		{
			if(ret[i] > n/2) {
				cout << i << endl;
				flag = 1;
			}
		}

		if(!flag)
			cout << -1 << endl;
	}
	return 0;
}
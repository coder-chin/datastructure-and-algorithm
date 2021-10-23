#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m;

	while(cin>>m && m) {
		vector<int> arr, ret;
		int tmp;

		for (int i = 0; i < m; ++i)
		{
			ret.push_back(0);
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}

		for (int i = 0; i < m; ++i)
		{
			int times = 0;
			for (int j = 0; j < m; ++j)
			{
				if(arr[j] < arr[i])
					times++;
			}
			ret[times] = arr[i];
		}

		cout << ret[0];

		for (int i = 1; i < m; ++i)
		{
			cout << " " << ret[i];
		}

		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num, tmp;

	while(cin>>num && num) {
		vector<int> arr, ret;

		for (int i = 1; i <= num; ++i)
			arr.push_back(i);

		for (int i = 0; i < num; ++i)
		{
			cin >> tmp;
			arr[tmp-1] = -1;
		}

		for (int i = 0; i < num; ++i)
		{
			if(arr[i]!=-1)
				ret.push_back(arr[i]);
		}

		if(ret.empty()) {
			cout << "Not Found";
		} else {
			cout << ret[0];
			for (unsigned int i = 1; i < ret.size(); ++i)
			{
				cout << " " << ret[i];
			}
		}
		cout << endl;
	}

	return 0;
}
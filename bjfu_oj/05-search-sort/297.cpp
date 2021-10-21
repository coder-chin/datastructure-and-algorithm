#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	while(cin>>n && n) {
		vector<int> arr;
		int tmp;
		int k=0;

		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}

		for (int i = 0; i < n; ++i)
		{
			if(arr[i]<0) {
				swap(arr[i], arr[k]);
				k++;
			}	
		}

		int i = 0;
		cout << arr[i];
		for (i=1; i < n; ++i)
		{
			cout << " " << arr[i];
		}

		cout << endl;
	}

	return 0;
}
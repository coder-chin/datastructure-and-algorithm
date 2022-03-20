#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, num, tmp;

	while(cin>>n && n) {
		vector<int> arr, old;

		for(int i=0; i<n; i++){
			cin >> tmp;
			arr.push_back(tmp);
		}

		cin >> num;

		for (int i = 0; i < n-1; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(arr[i]+arr[j]==num) 
					cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}
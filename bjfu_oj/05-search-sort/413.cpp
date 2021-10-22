#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findIndex(vector<int> arr, vector<int> old, int n, int num) {
	int slow = 0, fast = n-1;
	// cout << slow << fast << endl;

	while(slow<fast) {
		if(arr[slow]+arr[fast]<num) {
			slow++;
		} else if(arr[slow]+arr[fast]>num) {
			fast--;
		} else {
			int index1, index2;

			for (int i = 0; i < n; ++i)
			{
				if(old[i]==arr[slow])
					index1 = i;
				if(old[i]==arr[fast])
					index2 = i;
			}

			cout << index1 << " " << index2 << endl;
			break;
		}
	}
}

int main()
{
	int n, num, tmp;

	while(cin>>n && n) {
		vector<int> arr, old;

		for(int i=0; i<n; i++){
			cin >> tmp;
			arr.push_back(tmp);
		}

		old = arr;
		sort(arr.begin(), arr.end());

		cin >> num;

		findIndex(arr, old, n, num);
	}
	return 0;
}
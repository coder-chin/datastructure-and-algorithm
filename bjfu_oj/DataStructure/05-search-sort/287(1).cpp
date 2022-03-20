#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;

	while(cin>>num && num) {
		vector<int> arr;
		int tmp, searchNum, low, high, mid;
		bool flag = false;

		low = 0;
		high = num-1;

		for (int i = 0; i < num; ++i)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}
		
		cin >> searchNum;
		
		while(low<high) {
			mid = (low+high)/2;
			if(searchNum>arr[mid]) {
				low = mid+1;
			} else if(searchNum<arr[mid]) {
				high = mid-1;
			} else {
				flag = true;
				break;
			}
		}

		if(flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
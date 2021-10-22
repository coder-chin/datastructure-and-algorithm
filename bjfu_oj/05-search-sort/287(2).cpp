#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int searchNum;
bool flag;

void binarySearch(int low, int high) {
	// cout << low << " " << high << endl;
	int mid = (low+high)/2;
	if(low>=high)
		return;
	if(searchNum==arr[mid]) {
		flag = true;
		return;
	} else if(searchNum>arr[mid]) {
		low = mid+1;	
	} else if(searchNum<arr[mid]) {
		high = mid-1;
	}
	binarySearch(low, high);
}

int main()
{
	int num;

	while(cin>>num && num) {
		fill(arr.begin(), arr.end(), 0);
		int tmp, low, high;
		flag = false;
		low = 0;
		high = num-1;

		for (int i = 0; i < num; ++i)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}
		
		cin >> searchNum;
		
		binarySearch(low, high);

		if(flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

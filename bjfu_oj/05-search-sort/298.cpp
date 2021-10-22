#include <iostream>
#include <vector>
using namespace std;

int quickSortSearch(vector<int> arr, int slow, int fast, int key) {
	while(slow<fast) {
		if(arr[slow]>key && arr[fast]<key) {
			slow++, fast--;
		}
		while(slow<=fast && arr[fast]>key) 
			fast--;
		if(arr[fast]==key)
			return fast;

		while(slow<=fast && arr[slow]<key)
			slow++;
		if(arr[slow]==key)
			return slow;
	}

	return -1;
}

int main() 
{
	int num, tmp, key;

	while(cin>>num && num) {
		vector<int> arr;
		while(num--) {
			cin >> tmp;
			arr.push_back(tmp);
		}

		cin >> key;
		int ret = quickSortSearch(arr, 0, arr.size()-1, key);

		if(ret==-1) {
			cout << "not find" << endl;
		} else {
			cout << ret+1 << " " << key << endl;
		}
	}

	return 0;
}
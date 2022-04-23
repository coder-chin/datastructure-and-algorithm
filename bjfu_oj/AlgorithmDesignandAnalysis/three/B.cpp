#include <iostream>
#include <vector>
using namespace std;

int main() {
	int times, number, tmp;
	cin >> times;

	while(times) {
		cin >> number;
		vector<int> arr;
		for(int i = 0; i < number; i++) {
			cin >> tmp;
			arr.push_back(tmp);
		}
		int res = INT32_MIN;
		int sum = 0;
		for(unsigned int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if(sum > res) res = sum;
			if(sum <= 0) sum = 0;
		}
		cout << res << endl;
		times--;
	}
}
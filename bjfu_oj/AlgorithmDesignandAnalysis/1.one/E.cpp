#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;

	while(cin >> N) {
		vector<int> arr(N, 0);
		for (int i = 0; i < N; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());  //排序
		
		
	}

	return 0;
}

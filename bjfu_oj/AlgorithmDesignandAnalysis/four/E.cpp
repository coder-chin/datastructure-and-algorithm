#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;

	while(cin >> N) {
		int tmp;
		vector<int> nums;   //数字
		vector<int> dp;     //nums[i]结尾的最大和子序列

		for(int i = 0; i < N; i++) {
			cin >> tmp;
			nums.push_back(tmp);
			dp.push_back(tmp);
		}

		for (int i = 0; i < N; i++) {
    		for (int j = 0; j < i; j++) {
      		if (nums[i] > nums[j]) 
      			dp[i] = max(dp[i], dp[j] + nums[i]);
    		}
  		}

  		int res = nums[0];
  		for(int i = 0; i < N; i++) {
			res = max(res, dp[i]);
		}

		cout << res << endl;
	}
	return 0;
}

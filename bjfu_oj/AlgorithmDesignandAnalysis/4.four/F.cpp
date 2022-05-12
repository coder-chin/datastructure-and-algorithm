#include <bits/stdc++.h>
using namespace std;

// 完全背包问题
int main()
{
	int N, tmp;
	while(cin >> N) {
		vector<int> v;
		
		// 输入每段木材价值
		for(int i = 0; i < N; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		vector<int> dp(N+1, INT32_MIN);
		dp[0] = 0;

		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < i; j++) {
				dp[i] = max(dp[i], dp[i-j-1]+v[j]);
			}
		}

    	cout << dp[N] << endl;
	}
	return 0;
}
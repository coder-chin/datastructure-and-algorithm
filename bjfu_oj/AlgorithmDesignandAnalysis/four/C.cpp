#include <bits/stdc++.h>
using namespace std;

// 完全背包  一维简化
int main()
{
	int T, N, W;
	cin >> T;
	// T物品个数 W是背包重量

	for(int k = 0; k < T; k++) {
		cin >> N >> W;
		vector<int> dp(W+1, 0);
		vector<int> v(N, 0);
		vector<int> w(N, 0);

		for(int j = 0; j < N; j++) cin >> v[j];
		for(int j = 0; j < N; j++) cin >> w[j];

    	for(int i = 0; i < N; i++) { // 遍历物品
        	for(int j = w[i]; j <= W; j++) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;
}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, tmp, num;
	int mod = 1000000007;
	vector<int> dp(10000001, 0);
	dp[0] = 1, dp[1] = 1;

	for(int i = 2; i <= 10000000; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}

	cin >> N;
	for(int j = 0; j < N; j++) {
		cin >> tmp;
		num = tmp - 1;
		cout << dp[num] << endl;
	}

	return 0;
}

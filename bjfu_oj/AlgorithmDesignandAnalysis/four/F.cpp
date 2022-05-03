#include <bits/stdc++.h>
using namespace std;

// 完全背包问题
int main()
{
	int N, tmp;
	while(cin >> N) {
		vector<int> w, v;
		for(int i = 0; i <= N; i++) w.push_back(i);
		
		for(int i = 0; i < N; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
		for (int i = 1; i <= N; i++) 
        	dp[i][0] = v[i];

		for (int i = 1; i <= N; i++) {
	        for (int j = 1; j <= N; j++) {
	        	if (j - w[i-1] >= 0)
	                dp[i][j] = dp[i - 1][j] + dp[i][j - v[i-1]];
	            else 
	                dp[i][j] = dp[i - 1][j];

	            cout << "i: " << i << " j: " << j << " " << dp[i][j] << endl;
	        }  
    	}

    	cout << dp[N][N] << endl;
	}
	return 0;
}
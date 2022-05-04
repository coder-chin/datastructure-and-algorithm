#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int k = 0; k < T; k++) {
		int sum = 0;
		double P; 
		int N;
		cin >> P >> N;
		vector<double> chance(N+1);
		vector<int> v(N+1);

		for(int i = 1; i <= N; i++) {
			cin >> v[i] >> chance[i];
			sum += v[i];
		}

		vector<double> dp(10000, 0);
		dp[0] = 1.0;

		for(int i = 1;i <= N; i++){
			for(int j = sum; j >= v[i]; j--) {			//不被抓的概率 
				dp[j] = max(dp[j], dp[j-v[i]] * (1.0-chance[i]));
			}
		}

		for(int i = sum;i >= 0; i--) {					
			if((1.0-dp[i]) <= P) {
				printf("%d\n",i);
				break;
			}
		}
	}

	return 0;
}
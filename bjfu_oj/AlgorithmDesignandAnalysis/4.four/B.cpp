#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, row, tmp;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int res = INT32_MIN;
		cin >> row;
		vector<vector<int>> triangle;

		for(int i = 1; i <= row; i++) {
			vector<int> row;
			for(int j = 0; j < i; j++) {
				cin >> tmp;
				row.push_back(tmp);
			}
			triangle.push_back(row);
		}

		vector<vector<int>> dp(row, vector<int>(row));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        for (unsigned int j = 0; j < dp[row - 1].size(); j++) {
            res = max(res, dp[row - 1][j]);
        }

        cout << res << endl;
	}

	return 0;
}
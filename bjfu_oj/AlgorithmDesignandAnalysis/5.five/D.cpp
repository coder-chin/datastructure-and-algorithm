#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return b[1] > a[1];
}

int main()
{
	int N, x, y, res;

	while(cin >> N) {
		vector<vector<int>> timeTable;

		// 录入数据
		for(int i = 0; i < N; i++) {
			cin >> x >> y;
			timeTable.push_back({x, y});
		}

		sort(timeTable.begin(), timeTable.end(), cmp);  //排序

		res = 1;
		int end = timeTable[0][1];

		int i = 1;

		while(i < N) {
			if(timeTable[i][0] >= end) {
				end = timeTable[i][1];
				res++;
			}
			i++;
		}

		cout << res << endl;
	}

	

	return 0;
}

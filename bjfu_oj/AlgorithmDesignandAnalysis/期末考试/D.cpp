#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a - b > 0;
}

int main() {
	// 贪心
	int n, q;
	long long int tmp;
	scanf("%d%d", &n, &q);

	vector<long long int> amount, price;

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &tmp);
		amount.push_back(tmp);
	}
	// 降序排列
	// sort(amount.begin(), amount.end(), cmp);

	// 剪枝
	for (int i = 1; i < n; ++i) {
		amount[i] += amount[i-1];
	}

	for (int i = 0; i < q; ++i) {
		scanf("%lld", &tmp);

		int index = n-1;

		// 5 9 12
		while(amount[index] >= tmp && index >= 0) {
			index--;
		}
		index++;

		if(index == 0) printf("1\n");

		printf("%d\n", index+1);
	}

	return 0;
}

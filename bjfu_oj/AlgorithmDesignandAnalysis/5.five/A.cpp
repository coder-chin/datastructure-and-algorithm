#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> coins = {1, 2, 5, 10, 20, 50, 100};
	
	int T, res, m, index, item;

	cin >> T;

	while(T) {
		cin >> m;
		res = 0;
		index = 6;
		while(m) {
			item = m / coins[index];
			res += item;
			m -= item * coins[index];
			index--;
		}

		cout << res << endl;
		T--;
	}

	return 0;
}

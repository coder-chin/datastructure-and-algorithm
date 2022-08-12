#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, a, d, n, sum;
	cin >> T;

	while(T--) {
		cin >> a >> d >> n;
		sum = a * n + (n-1) * n * d / 2;

		cout << sum << endl;
	}

	return 0;
}
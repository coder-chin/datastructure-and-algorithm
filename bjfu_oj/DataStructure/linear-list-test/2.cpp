#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> arr, int n) {
	if(n==arr.size()-1) return arr[n];

	else return arr[n]+sum(arr, n+1);
}

int main()
{
	int m, n, tmp;

	while(cin>>m && m) {

		vector<int> a, b;
		for(int i=0; i<m; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}

		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}

		int sum1 = sum(a, 0);
		int sum2 = sum(b, 0);
		cout << sum1 << endl << sum2 << endl;
		
	}
	return 0;
}
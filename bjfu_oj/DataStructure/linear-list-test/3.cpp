#include <iostream>
#include <vector>
using namespace std;

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

		int i=0, j=0;
		while(i<m && j<n) {
			if(a[i]==b[j]) {
				i++, j++;
			} else {
				j = j-i+1;
				i = 0;
			}
		}
		if(i==m)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
		
	}
	return 0;
}
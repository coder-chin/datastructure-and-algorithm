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

				
		
	}
	return 0;
}
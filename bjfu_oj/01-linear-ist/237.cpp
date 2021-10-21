#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cnt;

	while(cin>>cnt) {
		if(!cnt) 
			break;

		vector<int> v1, v2, v3;
		int num;

		for(int i=0; i<cnt; i++) {
			cin >> num;
			v1.push_back(num);
		}
		for(int i=0; i<cnt; i++) {
			cin >> num;
			v2.push_back(num);
		}

		v3.resize(v1.size() + v2.size());
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		cout << v3[cnt-1] << endl;
	}

	return 0;
}
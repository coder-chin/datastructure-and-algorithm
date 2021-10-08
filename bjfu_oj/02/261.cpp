#include <iostream>
#include <vector>
using namespace std;

void split(vector<int> &v) {
	vector<int> pos, neg;

	for (unsigned int i = 0; i < v.size(); ++i)
		v[i] > 0 ? pos.push_back(v[i]) : neg.push_back(v[i]);

	v.resize(0);

	for (unsigned int i = 0; i < pos.size(); ++i)
		v.push_back(pos[i]);

	for (unsigned int i = 0; i < neg.size(); ++i)
		v.push_back(neg[i]);

}

int main()
{
	int n, tmp;

	while(cin>>n && n) {
		vector<int> a;

		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			a.push_back(tmp);
		}

		split(a);

		for (unsigned int i = 0; i < a.size()-1; ++i)
			cout << a[i] << " ";

		cout << a.back() << endl;
	}

	return 0;
}
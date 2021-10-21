#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> v, int n)
{
	if(n==0)
		return v[0];

	else if(v[n]>getMax(v, n-1)) 
		return v[n];

	else
		return getMax(v, n-1);
}

int main()
{
	int m, tmp;
	while(cin>>m && m)
	{
		vector<int> v;

		for (int i = 0; i < m; ++i)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		int max = getMax(v, m-1);

		cout << max << endl;
	}

	return 0;
}
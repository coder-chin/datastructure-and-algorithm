#include <iostream>
using namespace std;
int main()
{
	int n, m, k, cnt=0;;

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cnt++;
			if(cnt<=k)
				cout << "*";
			else 
				cout << ".";
		}
		cout << endl;
	}

	return 0;
}
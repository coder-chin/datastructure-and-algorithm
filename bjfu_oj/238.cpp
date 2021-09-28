#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	
	char ch;

	while(cin>>m && cin>>n)
	{
		if(!m && !n) break;

		vector<char> v1, v2;
		
		for(int i=0; i<m; i++) {
			cin >> ch;
			v1.push_back(ch);
		}
		for(int i=0; i<n; i++) {
			cin >> ch;
			v2.push_back(ch);
		}

		m--;
		n--;

		while(v1[m]==v2[n])
		{
			m--;
			n--;	
		}

		cout << v2[++n] << endl;
	}
}
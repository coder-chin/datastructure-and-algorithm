#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int length;
	while(cin>>length && length)
	{
		queue<int> q;
		int tmp;

		while(length--)
		{
			cin >> tmp;
			q.push(tmp);
		}
		int n = q.size();

		for (int i = 0; i < n-1; ++i)
		{
			cout << q.front() << " ";
			q.pop();
		}
		// cout << " out ";
		cout << q.front() << endl;
	}
	return 0;
}
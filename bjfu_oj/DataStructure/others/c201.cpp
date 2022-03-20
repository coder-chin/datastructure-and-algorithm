#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	int row = 1;

	while(row<=m)
	{
		int space = m-row;
		for (int i = 1; i <= space; ++i)
		{
			cout << " ";
		}
		for (int i = 1; i <= row; ++i)
		{
			cout << i;
		}
		for (int i = row-1; i > 0; --i)
		{
			cout << i;
		}
		cout << endl;

		row++;
	}

	return 0;
}
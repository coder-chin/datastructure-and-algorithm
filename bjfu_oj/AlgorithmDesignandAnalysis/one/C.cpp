#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;

	while(cin >> a >> b) {
		int aWin = 0, draw = 0, bWin = 0;

		for (int i = 1; i <= 6; ++i)
		{
			if(abs(a-i) > abs(b-i)) bWin++;
			else if(abs(a-i) < abs(b-i)) aWin++;
			else draw++;
		}

		cout << aWin << " " << draw << " " << bWin << endl;
	}

	return 0;
}

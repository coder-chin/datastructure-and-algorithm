#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	
	while(cin >> a >> b) {
		int index = 0;
		int MIN = 10e5;
		vector<int> arr(a);

		for (int i = 0; i < a; ++i)
			cin >> arr[i];
			
		int right = a-b+1;
		for (int i = 0; i < right; ++i)
		{
			int sum = 0;
			for (int j = 0; j < b; ++j)
				sum += arr[i+j];

			if(sum < MIN) {
				MIN = sum;
				index = i;
			}
		}

		cout << index+1 << endl;
	}

	return 0;
}

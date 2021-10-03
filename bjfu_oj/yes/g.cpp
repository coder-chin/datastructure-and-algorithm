#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, k;
	vector<int> arr;

	for (int i = 1; i < 10000; ++i)
	{
		if(i%3!=0 && i%10!=3)
			arr.push_back(i);
		if(arr.size()==1000)
			break;
	}

	cin >> t;
	while(t--)
	{
		cin >> k;
		cout << arr[k-1] << endl;
	}
	return 0;
}
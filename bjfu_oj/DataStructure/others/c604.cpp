#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num, tmp;
	vector<int> arr;

	cin >> num;

	while(num--)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	for (unsigned int i = 0; i < arr.size()-1; ++i)
	{
		for (unsigned int j = i+1; j < arr.size(); ++j)
		{
			if(arr[i]==arr[j])
			{
				arr.erase(arr.begin()+j);
				j--;
			}
		}
	}

	cout << arr.size() << endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
}
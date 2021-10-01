#include <iostream>
using namespace std;

bool isPrime(int n)
{
	bool flag = true;

	if(n==2)
		return true;

	if(n%2==0)
		return false;

	for (int i = 3; i*i <= n; i+=2)
	{
		if(n%i == 0) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main()
{
	int times, num;
	cin >> times;

	while(times--)
	{
		cin >> num;

		bool ret = isPrime(num);

		if(ret) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;

	}

	return 0;
}
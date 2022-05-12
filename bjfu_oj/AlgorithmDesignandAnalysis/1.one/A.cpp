#include <iostream>
using namespace std;

bool hasNumber(int num) {
	while(num) {
		if(num%10==4 || num%10==7) return true;
		else num/=10;
	}
	return false;
}

int main()
{
	int N;

	while(cin >> N) {
		int sum = 0;

		for(int i = 0; i <= N; i++) 
			if(hasNumber(i)) sum++;

		cout << N - sum << endl;
	}

	return 0;
}

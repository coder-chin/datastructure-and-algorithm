#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;  //个数
	int current, tmp; //当前数，和待处理的数
	int times;  //出现次数
	
	while(cin>>num && num!=0) {
		times = 0;
		vector<int> a;
		int n = num;

		while(num--) {
			cin >> tmp;
			a.push_back(tmp);

			if(times == 0) {
				current = tmp;
				times++;
			} else if(tmp == current) {
				times++; 
			} else {
				times--;
			}
		}

		if(times == 0) {
			cout << -1 << endl;
			continue;
		}

		times = 0;

		for (int item: a)
		{
			if(item==current)
				times++;
		}

		if(times > n/2)
			cout << current << endl;
		else
			cout << -1 << endl;	
	}

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;   //朋友数量，游戏轮数
	while(cin >> m >> n) {
		vector<int> people, res;
		int tmp;
		for(int i = 0; i < m; i++) {
			cin >> tmp;
			people.push_back(tmp);
		}
		for(int i = 0; i < n; i++) {
			cin >> tmp;   // 该回合的数字
			if(people[m-1] <= tmp) {  //最大的数字小于其
				res.push_back(people[m-1]);
				continue;
			} else if(people[0] >= tmp) {
				res.push_back(people[0]); //最小的数字大于其
				continue;
			}

			// 否则就是在中间
			// 3 6 9
			// 3 6 9
			int left = 0, right = m-1, mid;
			while(left <= right) {
				// cout << "left: " << left << " right: " << right << endl;
				if(people[left]<tmp && people[right]>tmp && (right-left)==1) {
					res.push_back(people[left]);
					break;
				}
				mid = (left + right) / 2;
				if(tmp > people[mid]) left = mid;
				else if(tmp < people[mid]) right = mid;
				else {
					res.push_back(tmp);
					break;
				}
			}
		}

		for(unsigned int i = 0; i < res.size()-1; i++) cout << res[i] << " ";

		cout << res[res.size()-1] << endl;
	}
}
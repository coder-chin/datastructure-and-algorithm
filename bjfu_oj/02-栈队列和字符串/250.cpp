#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int ack(int x, int y)
{
	int m=0; 
	int n=0;
	stack<vector<int>> sta;
	vector<int> tmp;


	tmp.push_back(x);
	tmp.push_back(y);

	sta.push(tmp);

	int ret = -1;

	while(!sta.empty()) {
		tmp = sta.top();
		sta.pop();

		if(tmp[0]==0) {
			ret = tmp[1]+1;
			if(sta.empty())
				break;
			tmp = sta.top();
			sta.pop();
			tmp[1] = ret;
			n = tmp[1];
			sta.push(tmp);
		}

		else if(tmp[1]==0) {
			tmp[0] = tmp[0]-1;
			tmp[1] = 1;
			sta.push(tmp);
		}
		else {
			vector<int> bot, top;
			bot.push_back(tmp[0]-1);
			m = tmp[0]-1;
			bot.push_back(-1);
			n = -1;
			sta.push(bot);
			
			top.push_back(tmp[0]);
			m = tmp[0];
			top.push_back(tmp[1]-1);
			n = tmp[1]-1;
			sta.push(top);
		}
	}

	return ret;
}

int main()
{
	int m, n;
	int result = 0;

	while(cin>>m>>n && m && n) {
		result = ack(m, n);
		cout << result << endl;
	}
	
	return 0;
}

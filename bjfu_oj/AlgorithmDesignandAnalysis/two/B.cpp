#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 拓扑排序 BFS
int main() {
	int m, n;
	cin >> m >> n; 
	// m个队  n场比赛
	vector<vector<int>> e; //领接表
	vector<int> ind;  //统计入度的数组
	vector<int> res; //保存结果的数组
	priority_queue<int> que;

	e.resize(m+1);
	ind.assign(m+1, 0);
	int t1, t2;

	// 构图
	for (int i = 0; i < n; ++i)
	{
		cin >> t1 >> t2;
		e[t1].push_back(t2);
		ind[t2]++;  // 入度++
	}

	// 拓扑排序的初始化
	for (int i = 1; i <= m; ++i)
	{
		if(ind[i]==0) que.push(i);
	}

	// BFS
	while(!que.empty()) {
		int top = que.top();
		que.pop();
		res.push_back(top);

		// 处理后事
		for (unsigned int i = 0; i < e[top].size(); ++i)
		{
			int num = e[top][i];
			ind[num]--;
			if(!ind[num]) que.push(num);
		}
	}

	sort(res.begin(), res.end());
	for (unsigned int i = 0; i < res.size()-1; ++i)
	{
		cout << res[i] << " ";
	}
	cout << res[res.size()-1];
}

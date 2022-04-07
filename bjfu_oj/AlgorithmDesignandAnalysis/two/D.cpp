#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 连通域 岛屿问题
int res = 0;
void dfs(vector<string> &arr, int i, int j) {
	// cout << i << " " << j << endl;
	int m = arr.size(), n = arr[0].length(); //宽和高
    if (i < 0 || j < 0 || i >= m || j >= n) return; // 越界

    if (arr[i][j] == 'R') return;
    else {
    	res++;   //a的+1
    }    
    // 将 (i, j) -> o
    arr[i][j] = 'R';
    dfs(arr, i + 1, j);
    dfs(arr, i, j + 1);
    dfs(arr, i - 1, j);
    dfs(arr, i, j - 1);
}

// 类比岛屿数量
int main()
{
	int m, n;

	while(cin >> m >> n) {
		res = 0;
		vector<string> arr;
		// input
		for (int i = 0; i < n; ++i) {
			string tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(arr[i][j] == 'G') dfs(arr, i, j);  //开始dfs
			}
		}

		cout << res << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 连通域 岛屿问题
int res = 0;
int maxNum = 0;
void dfs(vector<string> &arr, int i, int j) {
	int m = arr.size(), n = arr[0].length(); //宽和高
    if (i < 0 || j < 0 || i >= m || j >= n) return; // 越界
    if (arr[i][j] == 'o') return; // 已经是o
    else {
    	maxNum++;   //a的+1
    }    
    // 将 (i, j) -> o
    arr[i][j] = 'o';
    dfs(arr, i + 1, j);
    dfs(arr, i, j + 1);
    dfs(arr, i - 1, j);
    dfs(arr, i, j - 1);
}

// 类比岛屿数量
int main()
{
	int N;

	while(cin >> N && N != 0) {
		res = 0;
		vector<string> arr;
		// input
		for (int i = 0; i < N; ++i) {
			string tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}

		int m = N, n = arr[0].length(); //宽和高
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(arr[i][j] == 'a') dfs(arr, i, j);
				res = maxNum > res ? maxNum : res;
				maxNum = 0;
			}
		}

		cout << res << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;
#define MAX 100
#define inf 1e9

int arc[MAX][MAX];
int dis[MAX];
int path[MAX];
bool visited[MAX];
int vex[MAX];
int n; //chengshi
int m; //biann

struct Node {
	int num;
	char ch;
} node[MAX];

void DFS(int a) {
	visited[a] = true;
	dis[a] = 0;

	int ans = inf;
	int k;  //记录当前最小下标

	for (int i = 1; i <= n; ++i)
	{
		dis[i] = arc[a][i];
	}  //起点到改点的距离

	for (int i = 1; i <= n; ++i)
	{
		ans = inf;
		for (int j = 1; j <= n; ++j)
		{
			if(!visited[j] && dis[j]<ans) {
				ans = dis[j];
				k = j;
			}
		}

		visited[k] = true;

		for (int i = 1; i <= n; ++i)
		{
			if(dis[i] > dis[k]+arc[k][i]) {
				dis[i] = dis[k]+arc[k][i];
				path[i] = k;
				// cout << "last node: " << k << endl;
			}
		}

	}
}

void print(int n) {
	// cout << "suoyin: " << n << endl;
	if(path[n]==n){
		// cout << "end: " << n << endl;
		cout << node[n].ch;
		return;
	}

	print(path[n]);
	// cout << "space " << n << endl;
	cout << " " << node[n].ch;
}

int main()
{
	char cityOne, cityTwo;
	int city1, city2;
	int dist;

	while(cin>>n>>m && m && n) {
		for (int i = 1; i <= MAX; ++i) {
			visited[i] = false;
			dis[i] = 0;
			for (int j = 1; j <= MAX; ++j)
			{
				if(i==j)
					arc[i][j] = 0;
				else 
					arc[i][j] = inf;
			}
		}

		for (int i = 1; i <= n; ++i) {
			cin >> node[i].ch; //a1 b2 c3
			node[i].num = i;
		}

		for (int i = 1; i <= m; ++i) {
			cin >> cityOne >> cityTwo >> dist;
			for (int i = 1; i <= n; ++i)
			{
				if(node[i].ch==cityOne)
					city1 = node[i].num;
				if(node[i].ch==cityTwo)
					city2 = node[i].num;
			}
			arc[city1][city2] = arc[city2][city1] = dist;
		}

		cin >> cityOne >> cityTwo;
		for (int i = 1; i <= n; ++i) {
			if(node[i].ch==cityOne)
				city1 = node[i].num;
			if(node[i].ch==cityTwo)
				city2 = node[i].num;
		}

		for (int i = 1; i <= n; ++i)
		{
			path[i] = city1;
		}

		DFS(city1);

		cout << dis[city2] << endl;

		print(city2);

		cout << endl;

	}
	return 0;
}

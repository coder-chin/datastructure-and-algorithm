#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define inf 1e9

int arcs[MAX][MAX];
int visited[MAX];
int dis[MAX];
int m, n, p, q;

void Dijkstra(int index) {
	dis[index] = 0;
	visited[index] = true;

	int tmpDis, k;

	for(int i=1; i<=m; i++) {
		dis[i] = arcs[index][i];
	}
	
	for(int j=0; j<m-1; j++)
	{
		tmpDis = inf;
		for(int i=1; i<=m; i++)
		{
			if(!visited[i] && dis[i]<=tmpDis) {
				tmpDis = dis[i];
				k = i;
			}
		}
		
		visited[k] = true;

		for(int i=1; i<=m; i++) {
			if(!visited[i] && dis[i]>dis[k]+arcs[k][i]) {
				dis[i]= dis[k]+ arcs[k][i];
			}
		}
	}
}

int main() {
	int x, y, val;

	while(cin >> m >> n >> p >> q) {
		for(int i=1; i<=m; i++) {
			visited[i] = false; // no visit
			for(int j=1; j<=m; j++){
				if(i==j)   arcs[i][j] = 0;
				arcs[i][j] = inf;
			}
		}

		while(n--)
		{
			cin >> x >> y >> val;
			arcs[x][y] = min(val, arcs[x][y]);
			arcs[y][x] = min(val, arcs[y][x]);
		}

		Dijkstra(p);

		// for(int i = 1; i <=m; i++) cout << dis[i] << endl;
		if(dis[q] == inf) cout << -1 << endl;
		else cout << dis[q] << endl;
	}
	
	return 0;
}

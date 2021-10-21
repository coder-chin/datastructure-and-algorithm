#include<iostream>
using namespace std;

#define MAX 100
#define inf 1e9

typedef struct {
	int vexnum;
	int arcnum;
	int arcs[MAX][MAX];

	int visited[MAX];
	int dis[MAX];
	// int path[MAX];
}Graph;

void Dijkstra(Graph& gra, int index)
{
	gra.dis[index] = 0;
	// gra.path[index] = 0;
	gra.visited[index] = true;

	int tmpDis, k;

	for(int i=1; i<=gra.vexnum; i++) {
		gra.dis[i] = gra.arcs[index][i];
		// cout << "julifuzhi: " << gra.dis[i] << endl;
	}
	
	for(int j=0; j<gra.vexnum-1; j++)
	{
		tmpDis = inf;
		for(int i=1; i<=gra.vexnum; i++)
		{
			if(!gra.visited[i] && gra.dis[i]<tmpDis)
			{
				tmpDis = gra.dis[i];
				k = i;
			}
		}
		// cout << "k is true " << k << endl;
		gra.visited[k] = true;

		for(int i=1; i<=gra.vexnum; i++)
		{
			if(!gra.visited[i] && gra.dis[i]>gra.dis[k]+gra.arcs[k][i]) {
				gra.dis[i]= gra.dis[k]+ gra.arcs[k][i];
				// cout << "next path: "  << i << " " << gra.dis[i] << endl;
			}
		}
	}
}

int main()
{
	int m, n;
	int x, y, val;
	int begin;

	while(cin>>m>>n && m && n)
	{
		Graph gra;
		gra.vexnum = m; //dingdian
		gra.arcnum = n; //bian

		for(int i=1; i<=m; i++) {
			gra.visited[i] = false; // no visit
			for(int j=1; j<=m; j++)
				gra.arcs[i][j] = inf;  
		}

		while(n--)
		{
			cin >> x >> y >> val;
			gra.arcs[x][y] = gra.arcs[y][x] = val;
		}

		cin >> begin;

		Dijkstra(gra, begin);

		int ans, max=-1;

		for(int i=1; i<=gra.vexnum; i++)
		{
			if(gra.dis[i]>max && gra.dis[i]<inf)
			{
				max = gra.dis[i];
				ans = i;
			}
		}

		cout << ans << endl << max << endl;
	}
	
	return 0;
}

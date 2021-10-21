#include <iostream>
#include <vector>
using namespace std;
#define inf 1e9
#define MAX 100

int visited[MAX];
int dis[MAX];
int arcs[MAX][MAX];

int m, n;

void Dijkstra(int a) {
	visited[a] = 1;
	int tmpDis, k;

	for (int i = 1; i <= m; ++i)
		dis[i] = arcs[a][i];

	for(int j=1; j<=m-1; j++)
	{
		tmpDis = inf;
		for(int i=1; i<=m; i++)
		{
			if(!visited[i] && dis[i]<tmpDis)
			{
				tmpDis = dis[i];
				k = i;
			}
		}
		
		visited[k] = true;

		for(int i=1; i<=m; i++)
		{
			if(!visited[i] && dis[i]>dis[k]+arcs[k][i]) {
				dis[i]= dis[k]+ arcs[k][i];
				// cout << i << ": " << dis[i] << endl;
			}
		}
	}

}

int main()
{
	while(cin>>m>>n && m && n) {
		int j, k;
		int index;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j)
			{
				if(i==j)
					arcs[i][j]=0;
				else
					arcs[i][j] = inf;
			}
		}

		while(n--) {
			cin >> j >> k;
			arcs[j][k] = arcs[k][j] = 1;
		}

		for (index = 1; index <= m; index++)
		{
			for (int i = 1; i <= m; ++i)
			{
				visited[i] = 0;
				dis[i] = 0;
			}
			
			Dijkstra(index); //从i开始到各个节点的距离

			double people = 0;

			for (int k = 1; k <= m; ++k)
			{
				if(dis[k]-dis[index]<=6) 
					people++;
			}
		
			printf("%d: %.2f", index, people/m*100);
			cout << "%" << endl;
		}		
	}

	return 0;
}
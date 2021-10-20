#include <iostream>
#include <vector>
using namespace std;
 
#define MAX 100
 
typedef struct {
	int vexnum;  //dian
	int arcnum;  //bian
	vector<vector<int>> node;  // juzhen
} AMGraph;
 
void createMatrix(AMGraph &gra, int m, int n) {
	gra.node.resize(MAX, vector<int>(MAX, 0));
 
	gra.vexnum = m;
	gra.arcnum = n;
 
	int x, y;
 
	// 绘制边框
	for (int i = 0; i <= m; ++i)
	{
		gra.node[i][0] = gra.node[0][i] = i;
	}
 
	// 绘制联通的线
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		gra.node[x][y] = gra.node[y][x] = 1;
	}
}
 
void deleteVex(AMGraph &gra) {
	int dot;

	cin >> dot;

	for (int i = 0; i <= gra.vexnum; ++i) {
		gra.node[i][dot] = gra.node[dot][i] = -1;
	}

}
 
void printGraph(AMGraph &gra) {
	int n = gra.vexnum;
	// cout << "n is: " << n << endl;
 
	for (int i = 0; i <= n; ++i)
	{
		int tag = 0;

		for (int j=0; j <= n; ++j)
		{
			if(gra.node[i][j]!=-1) {
				cout << gra.node[i][j];
				tag++;
			} 
			// cout << "tag is: " <<  tag << endl;
			if(tag<n && gra.node[i][j]!=-1) {
				cout << "|";
			}
		}

		gra.node[i][0]!=-1 &&  cout << endl;
	}
}
 
int main()
{
	int m, n;
	while(cin >> m >> n && m && n) {
		AMGraph matrix;
 
		createMatrix(matrix, m, n);
		deleteVex(matrix);
		// cout << matrix.vexnum << endl;
		printGraph(matrix);
	} 
 
	return 0;
}
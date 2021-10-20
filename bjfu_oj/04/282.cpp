#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 100

vector<int> visited(100);
int tag;

typedef struct GNode{
	int data;
	bool exist;
	struct GNode* next;
} GNode, *GList;

typedef struct {
	int vexnum;
	int arcnum;
	GList node[MAX];
} ALGraph;

void createADL(ALGraph &gra, int m, int n) {
	gra.vexnum = m;
	gra.arcnum = n;

	int l, r;

	for (int i = 1; i <= m; ++i)
	{
		gra.node[i] = new GNode; 
		gra.node[i]->data = i;
		gra.node[i]->exist = true;
		gra.node[i]->next = NULL;
	}
    
    // 前插
	for (int j = 0; j < n; ++j)
	{
		cin >> l >> r;
		
		GNode *p = new GNode;
		p->data = r;

		GList p1 = gra.node[l];

		while(p1->next) 
			p1 = p1->next;

		p->next = NULL;
		p1->next = p;

		GNode *q = new GNode;
		q->data = l;

		GList q1 = gra.node[r];
		while(q1->next) 
			q1 = q1->next;

		q->next = NULL;
		q1->next = q;
	}
}
	
void DFS(ALGraph gra, int n) {
	visited[n] = 1;
	tag++;
	// cout << "taged: " << tag << endl;

	if(gra.vexnum == tag)
		cout << n;

	else 
		cout << n << " ";
	

	GList p = gra.node[n]->next;

	while(p) {
		if(visited[p->data]==0) {
			DFS(gra, p->data);
		}
		p = p->next;
	}
}

int main()
{
	int n, m;

	while(cin>>m>>n && m && n) {
		fill(visited.begin(), visited.end(), 0);
		ALGraph gra;
		tag = 0;

		createADL(gra, m, n);

		int node;
		cin >> node;

		DFS(gra, node);

		cout << endl;
	}
	return 0;
}

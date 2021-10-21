#include <iostream>
using namespace std;

#define MAX 100

typedef struct GNode{
	int data;
	struct GNode* next;
} GNode, *GList;

typedef struct {
	int vexnum;
	int arcnum;
	GNode node[MAX];
}ALGraph;

void createADL(ALGraph &gra, int m, int n) {
	gra.vexnum = m;
	gra.arcnum = n;

	int l, r;

	for (int i = 1; i <= m; ++i)
	{
		gra.node[i].data = i;
		gra.node[i].next = NULL;
	}

	for (int j = 0; j < n; ++j)
	{
		cin >> l >> r;

		GNode *p = new GNode;
		p->data = r;
		p->next = gra.node[l].next;
		gra.node[l].next = p;

		GNode *q = new GNode;
		q->data = l;
		q->next = gra.node[r].next;
		gra.node[r].next = q;
	}
}

void insertVex(ALGraph &gra) {
	gra.vexnum++;
	int n = gra.vexnum;
	int num;

	cin >> num;

	gra.node[n].data = num;
	gra.node[n].next = NULL;
}

void printGraph(ALGraph &gra) {
	for (int i = 1; i <= gra.vexnum; ++i)
	{
		cout << gra.node[i].data;
		if(!gra.node[i].next) {
			cout << endl;
			return ;
		}

		GList ptr = gra.node[i].next;
		while(ptr) {
			cout << " " << ptr->data ;
			ptr = ptr->next;
		}
		cout << endl;
	}	
}

int main()
{
	int n, m;

	while(cin>>m>>n && m && n) {
		ALGraph gra;
		createADL(gra, m, n);
		insertVex(gra);
		printGraph(gra);
	}
	return 0;
}
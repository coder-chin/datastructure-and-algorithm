#include <iostream>
using namespace std;

#define MAX 100

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

	for (int j = 0; j < n; ++j)
	{
		cin >> l >> r;

		GNode *p = new GNode;
		p->data = r;
		p->next = gra.node[l]->next;
		gra.node[l]->next = p;

		GNode *q = new GNode;
		q->data = l;
		q->next = gra.node[r]->next;
		gra.node[r]->next = q;
	}
}

void deleteArc(ALGraph &gra) {
	int x, y;
	cin >> x >> y;

	GList slow = gra.node[x];
	GList fast = slow->next;

	while(fast) {
		if(fast->data==y) {
			fast = fast->next;
			slow->next = fast;
		} else {
			slow = slow->next;
			fast = fast->next;
		}
	}

	GList slow2 = gra.node[y];
	GList fast2 = slow2->next;

	while(fast2) {
		if(fast2->data==x) {
			fast2 = fast2->next;
			slow2->next = fast2;
		} else {
			slow2 = slow2->next;
			fast2 = fast2->next;
		}
	}
}	

void printGraph(ALGraph &gra) {
	for (int i = 1; i <= gra.vexnum; ++i)
	{
		cout << gra.node[i]->data;
		if(gra.node[i]->next) {
			GList ptr = gra.node[i]->next;
			while(ptr) {
				cout << " " << ptr->data ;
				ptr = ptr->next;
			}
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
		deleteArc(gra);
		printGraph(gra);
	}
	return 0;
}

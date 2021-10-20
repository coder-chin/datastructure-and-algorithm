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

void deleteVex(ALGraph &gra) {
	int num;
	cin >> num;

	gra.node[num]->exist = false;

	for (int i = 1; i <= gra.vexnum; ++i)
	{
		if(gra.node[i]->exist) {
			GList slow = gra.node[i];
			GList fast = slow->next;
			
//			cout << fast->data << endl;
			
			while(fast) {
				if(fast->data == num) {
					fast = fast->next;	
					slow->next = fast;
				}
				else {
					slow = slow->next;
					fast = slow->next;
				}
			}
		}
	}
}

void printGraph(ALGraph &gra) {
	for (int i = 1; i <= gra.vexnum; ++i)
	{
		if(gra.node[i]->exist) {
			cout << gra.node[i]->data;
			GList ptr = gra.node[i]->next;
			while(ptr) {
				cout << " " << ptr->data ;
				ptr = ptr->next;
			}
			cout << endl;
		}	
	}	
}

int main()
{
	int n, m;

	while(cin>>m>>n && m && n) {
		ALGraph gra;
		createADL(gra, m, n);
		deleteVex(gra);
		printGraph(gra);
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct LNode{
	int data;
	LNode* next;
}LNode, *LinkList;

void createLink(LinkList &L, int n) {
	L = new LNode;
	L->next = NULL;
	LinkList link = L;

	for (int i = 0; i < n; ++i)
	{
		LNode *p = new LNode;
		cin >> p->data;
		p->next = NULL;
		link->next = p;
		link = link->next;
	}
}

void sort(LinkList &L) {
	LinkList p = L->next;
	LinkList q, tmp;
	
	while(p->next) {
		q = p->next;
		tmp = p;
		while(q) {
			if(q->data < tmp->data) {
				tmp = q;
			}
			q = q->next;
		}
		swap(p->data, tmp->data);
		p = p->next;
	}
}

void printNode(LinkList L) {
	L = L->next;
	cout << L->data;
	L = L->next;

	while(L) {
		cout << " " << L->data;
		L = L->next;
	}
	cout << endl;
}

int main()
{
	int m;

	while(cin>>m && m) {
		LinkList p;
		createLink(p, m);
		sort(p);
		printNode(p);
	}
}

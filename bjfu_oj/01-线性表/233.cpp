#include <iostream>
#include <string>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *pre, *next;
}LNode, *LinkList;

bool init(LinkList &L, int n)
{
	L->next = NULL;
	LinkList p = L;

	for(int i=1; i<=n; i++)
	{
		LNode *tmp = new LNode;
		cin >> tmp->data;
		p->next = tmp;
		tmp->pre = p;
		p = p->next;
	}
	p->next = NULL;

	return true;
}

bool swap(LinkList L)
{
	int loc;
	cin >> loc;
	LinkList p = L;

	for (int i = 1; i <= loc; i++)
		p = p->next;

	p->pre->next = p->next;
	p->pre->pre->next = p;
	p->next = p->pre;

	

	L = L->next;
	while(L->next)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << L->data << endl;

	return true;
}

int main()
{
	int m;
	while(cin>>m)
	{
		if(!m) break;

		LinkList L = new LNode;

		init(L, m);
		swap(L);
	}

	return 0;
}
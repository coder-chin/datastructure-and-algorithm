#include <iostream>
#include <string>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
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
		p = p->next;
	}
	p->next = NULL;

	return true;
}

bool divide(LinkList L)
{
	LinkList p = L->next;
	LinkList pos = new LNode;
	pos->next = NULL;
	LinkList m = pos;

	LinkList neg = new LNode;
	neg->next = NULL;
	LinkList n = neg;

	while(p)
	{
		if(p->data < 0)
		{
			n->next = p;
			n = n->next;
		}
		else
		{
			m->next = p;
			m = m->next;
		}
		p = p->next;
	}

	m->next = NULL;
	n->next = NULL;

	pos = pos->next;
	neg = neg->next;

	while(neg->next)
	{
		cout << neg->data << " ";
		neg = neg->next;
	}
	cout << neg->data << endl; 

	while(pos->next)
	{
		cout << pos->data << " ";
		pos = pos->next;
	}
	cout << pos->data << endl;

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
		divide(L);
	}

	return 0;
}
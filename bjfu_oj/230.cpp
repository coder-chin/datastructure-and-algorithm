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

bool findMax(LinkList L)
{
	L = L->next;
	int max = L->data;

	L = L->next;
	while(L)
	{
		max = max>L->data ? max : L->data;
		L = L->next;
	}

	cout << max << endl;
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
		findMax(L);
	}

	return 0;
}
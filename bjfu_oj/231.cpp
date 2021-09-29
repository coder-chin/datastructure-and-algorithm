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
		tmp->next = p->next;
		p->next = tmp;
	}

	return true;
}

void output(LinkList L)
{
	L = L->next;
	while(L->next)
	{
		cout << L->data << " ";
		L = L->next;
	}
	cout << L->data << endl;
}


int main()
{
	int m;
	while(cin>>m)
	{
		if(!m) break;

		LinkList L = new LNode;

		init(L, m);
		output(L);
	}

	return 0;
}
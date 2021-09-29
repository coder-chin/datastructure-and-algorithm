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

bool merge(LinkList &L1, LinkList &L2)
{
	LinkList ret = new LNode;

	LinkList p = ret;
	LinkList p1 = L1->next;
	LinkList p2 = L2->next;

	while(p1 && p2)
	{
		if(p1->data == p2->data)
		{
			p->next = p1;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1->data > p2->data) 
		{
			p->next = p2;
			p = p->next;
			p2 = p2->next;
		}
		else {
			p->next = p1;
			p = p->next;
			p1 = p1->next;
		}
	}

	p->next = p1 ? p1 : p2;

	ret = ret->next;
	while(ret->next) {
		cout << ret->data << " ";
		ret = ret->next;
	}
	cout << ret->data << endl;

	return true;
}

int main()
{
	int m, n;
	while(cin>>m && cin>>n)
	{
		if(!m && !n) break;

		LinkList L1 = new LNode;
		LinkList L2 = new LNode;

		init(L1, m);
		init(L2, n);
		merge(L1, L2); 
	}

	return 0;
}
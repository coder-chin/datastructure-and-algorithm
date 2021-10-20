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

bool calc(LinkList L1, LinkList L2) 
{
	LinkList p1 = L1->next;
	LinkList p2 = L2->next;

	LinkList p = new LNode;
	p->next = NULL;
	LinkList ptr = p;
	int num = 0;

	while(p1)
	{
		int flag=1;
		while(p2&&flag) {
			if(p1->data == p2->data) {
				flag = 0;
				break;
			}
			p2 = p2->next;
		}
		if(flag) {
			num++;
			ptr->next = p1;
			ptr = ptr->next;
		}
		p1 = p1->next;
		p2 = L2->next;
	}
	ptr->next = NULL;

	p = p->next;
	while(p->next)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
	cout << num << endl;

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
		calc(L1, L2);
	}

	return 0;
}
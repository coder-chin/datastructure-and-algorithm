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

bool deletePart(LinkList L)
{
	int min, max;
	cin >> min >> max;

	LinkList slow = L;
	LinkList fast = L->next;

	while(fast)
	{
		if(fast->data>=min && fast->data<=max)
		{
			slow->next = fast->next;
			fast = fast->next;
		}
		else {
			slow = slow->next;
			fast = fast->next;
		}
	}

	L = L->next;
	while(L->next) {
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
		deletePart(L);
	}

	return 0;
}
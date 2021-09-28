#include <iostream>
#include <cmath>
using namespace std;

typedef struct LNode {
	int num;
	struct LNode *pre;
	struct LNode *next;
}LNode, *LinkList;

void init(LinkList L, int cnt)
{
	int tmp = 0;
	LNode *ptr = L;

	for(int i=1; i<=cnt; i++)
	{
		LNode *node = new LNode;
		cin >> tmp;
		node->num = tmp;
		ptr->next = node;
		node->pre = ptr;
		ptr = ptr->next;
	}

	ptr->next = NULL;
}

void output(LinkList L)
{
	int val;
	cin >> val;
	LinkList p = L->next;

	while(p && p->next)
	{
		if(p->num==val)
		{
			p->next->pre = p->pre;
			p->pre->next = p->next;
		}
			p = p->next;
	}

	if(p->num==val)
		p->pre->next = NULL;


	L = L->next;
	while(L->next)
	{
		cout << L->num << " ";
		L = L->next;
	}
	cout << L->num;
	cout << endl;
}


int main()
{
	int cnt;
	while(cin>>cnt)
	{
		if(!cnt) break;

		LNode *L = new LNode;
		init(L, cnt);
		output(L);
	}
	return 0;
}
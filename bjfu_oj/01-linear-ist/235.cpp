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
	LNode *ptr = L;  //头指针

	for(int i=1; i<=cnt; i++)
	{
		LNode *node = new LNode;
		cin >> tmp;
		node->num = tmp;
		node->next = ptr->next;
		ptr->next = node;
	}
}

void output(LinkList L)
{
	int loc;
	cin >> loc;

	for(int i=1; i<=loc; i++)
	{
		L = L->next;
	}

	cout << L->num << endl;
}

int main()
{
	int cnt;
	while(cin>>cnt)
	{
		if(!cnt) break;

		LNode *L = new LNode;
		L->next = NULL;
		init(L, cnt); //头插法
		output(L);
	}
	return 0;
}
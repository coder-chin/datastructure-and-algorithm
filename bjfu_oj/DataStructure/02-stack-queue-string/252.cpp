#include <iostream>
using namespace std;
 
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;
 
void init(LinkList &L)
{
	L->next = NULL;
}
 
void input(LinkList L, int m)
{
	LinkList p = L;
 
	while(m--) {
		LNode *node = new LNode;
		cin >> node->data;  //输入
		node->next = NULL;
		p->next = node;
		p = p->next;
	}
}
 
int getSum(LinkList L)
{
	if(!L->next)
		return 0;
 
	else
		return 1+getSum(L->next);
}
 
int main()
{
	int m;
 
	while(cin>>m && m)
	{
		LinkList L = new LNode;
		init(L);
		input(L, m);
		int sum = getSum(L);
		cout << sum << endl;
	}
 
	return 0;
}
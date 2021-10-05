#include <iostream>
#include <iomanip>
using namespace std;

typedef struct LNode {
	double data;
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

double getSum(LinkList L)
{
	if(!L)
		return 0;

	else
		return L->data+getSum(L->next);
}

int main()
{
	int m;

	while(cin>>m && m)
	{
		LinkList L = new LNode;
		init(L);
		input(L, m);
		double sum = getSum(L);

		cout << fixed << setprecision(2) << sum/m << endl;
	}

	return 0;
}
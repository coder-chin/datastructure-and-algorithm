#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0

typedef struct LNode{
	int number;
	struct LNode *next; 
}LNode, *LinkList;

int Init(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}
int Input(LinkList &L, int length) {
	LinkList p = L;
	
	while(length) 
	{
		LinkList q = new LNode;
		cin >> q->number;
		q->next = NULL;
		length--;
		p->next = q;
		p = p->next;
	}
	return OK;
}
void kmp(LinkList L1, LinkList L2) {
	LinkList p = L1->next;
	LinkList q = L2->next;
	LinkList tmp = q;

	while(p && q) {
		if(p->number == q->number) {
			p = p->next;
			q = q->next;
		} else {
			p = L1->next;
			q = tmp->next;
			tmp = tmp->next;
		}
	}

	if(!p) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	int m, n;
	while(cin>>m && m) {
		LinkList L1, L2;

		Init(L1);
		Init(L2);

		Input(L1, m);
		cin >> n;
		Input(L2, n);

		kmp(L1, L2);
	}
	
	return 0;
}


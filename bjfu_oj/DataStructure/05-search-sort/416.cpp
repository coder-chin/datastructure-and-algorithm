#include <iostream>
#include <algorithm>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

void createLink(LinkList &L, int n) {
	L = new LNode;  //头结点
	L->next = NULL;
	LinkList ptr = L;

	for (int i = 0; i < n; ++i)
	{
		LNode *p = new LNode;
		cin >> p->data;
		p->next = NULL;
		ptr->next = p;
		ptr = ptr->next;
	}
}

void exchangeNode(LinkList &L, int n) {
	LinkList ptr = L;
	ptr = ptr->next;

	for (int i = 1; i <= n; i+=2)
	{
		if(ptr->next) {
			swap(ptr->data, ptr->next->data);
			ptr = ptr->next->next;	
		}
	}
}

void printNode(LinkList L) {
	L = L->next;
	cout << L->data;
	L = L->next;

	while(L) {
		cout << " " << L->data;
		L = L->next;
	}
	cout << endl;
}

int main() 
{
	int num;

	while(cin>>num && num) {
		LinkList L;

		createLink(L, num);
		exchangeNode(L, num);
		printNode(L);
	}

	return 0;
}
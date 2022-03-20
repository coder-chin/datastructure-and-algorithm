#include <iostream>
using namespace std;

typedef struct LNode{
	int data;
	LNode* next;
}LNode, *LinkList;

void createLink(LinkList &head, int n) {
	head = new LNode;
	LinkList p = head;
	cin >> p->data;

	for (int i = 1; i < n; ++i)
	{
		LNode* node = new LNode;
		node->next = NULL;
		cin >> node->data;
		p->next = node;
		p = p->next;
	}
}


void findNode(LinkList p, int k) {
	LinkList slow = p;
	LinkList fast = p;

	for (int i = 0; i < k-1; ++i)
	{
		fast = fast->next;
	}

	while(fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	cout << slow->data << endl;
}

int main()
{
	int num;

	while(cin>>num && num) {
		LinkList p;
		int k;

		createLink(p, num);
		cin >> k;

		findNode(p, k);
	}

	return 0;
}

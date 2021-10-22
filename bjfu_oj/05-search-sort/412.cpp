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
		//cout << "local: " << i << endl;
		LNode* node = new LNode;
		node->next = NULL;
		cin >> node->data;
		p->next = node;
		p = p->next;
	}
}

LinkList splitLink(LinkList p, int num) {
	LinkList head1 = p;
	// cout << head1->data << endl;

	LinkList m = p;
	p = p->next;

	LinkList head2 = p;
	LinkList n = p;
	p = p->next; 

	for (int i = 3; i <= num; ++i)
	{
		//cout << p->data << endl;
		if(i%2) {
			m->next = p;
			m = m->next;
		} else {
			n->next = p;
			n = n->next;
		}
		p = p->next;
	}

	m->next = head2;
	n->next = NULL;

	return head1;
}

void printLink(LinkList p) {
	while(p->next) {
		cout << p->data << " ";
		p = p->next;
	}

	cout << p->data << endl;
}

int main()
{
	int num;

	while(cin>>num && num) {
		LinkList p;
		LinkList q;

		createLink(p, num);
		q = splitLink(p, num);
		printLink(q);
	}

	return 0;
}

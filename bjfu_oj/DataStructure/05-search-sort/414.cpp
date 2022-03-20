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

void printLink(LinkList p) {
	while(p->next) {
		cout << p->data << " ";
		p = p->next;
	}

	cout << p->data << endl;
}

void deleteNode(LinkList &p, int k, int num) {
	if(num==k) {
		p = p->next;
		return;
	}

	LinkList ptr = p;
	int index = num-k;

	for (int i = 1; i <= index-1; ++i)
	{
		ptr = ptr->next;
	}

	ptr->next = ptr->next->next;
}

int main()
{
	int num;

	while(cin>>num && num) {
		LinkList p;
		int k;

		createLink(p, num);
		cin >> k;

		if(num==1) {
			cout << "The LinkList is Empty !" << endl;
			continue;
		}

		deleteNode(p, k, num);
		printLink(p);
	}

	return 0;
}

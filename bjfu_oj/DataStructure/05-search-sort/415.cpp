#include <iostream>
#include <string>
using namespace std;

typedef struct LNode{
	int data;
	LNode* next;
}LNode, *LinkList;

void createLink(LinkList &L, int n) {
	L = new LNode;
	L->next = NULL;

	for (int i = 0; i < n; ++i)
	{
		LNode *p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

LinkList getSumLink(LinkList L1, LinkList L2) {
	LinkList sum = new LNode; //新链表
	sum->next = NULL;
	LinkList ptr = sum;
	int tmp;
	bool higher = false;

	L1 = L1->next;
	L2 = L2->next;

	while(L1 && L2) {
		LNode *p = new LNode;
		p->next = NULL;
		if(higher) {
			tmp = L1->data+L2->data+1;
			higher = false; //消除进位
		} else {
			tmp = L1->data+L2->data;
		}

		L1 = L1->next;
		L2 = L2->next;

		if(tmp<10) {
			p->data = tmp;
		} else {
			p->data = tmp%10;
			higher = true; // 表示进位
		}

		ptr->next = p;
		ptr = ptr->next;
	}

	LinkList last = L1 ? L1 : L2; 

	while(last) {
		// cout << "数是: " << last->data << endl;
		LNode *p = new LNode;
		p->next = NULL;
		if(higher) {
			tmp = last->data+1;
			higher = false; //消除进位
		} else {
			tmp = last->data;
		}

		if(tmp<10) {
			p->data = tmp;
		} else {
			p->data = tmp%10;
			higher = true; // 表示进位
		}

		last = last->next;
		ptr->next = p;
		ptr = ptr->next;
	}

	if(higher) {
		LNode *p = new LNode;
		p->data = 1;
		p->next = NULL;
		ptr->next = p;
	}

	return sum;
}

int main() {
	int m, n;
	while(cin>>m>>n && m && n) {
		LinkList L1;
		LinkList L2;
		LinkList L3;

		createLink(L1, m);
		createLink(L2, n);

		L3 = getSumLink(L1, L2);
		L3 = L3->next;
		cout << L3->data;
		L3 = L3->next;

		while(L3) {
			cout << " " << L3->data;
			L3 = L3->next;
		}
			
		cout << endl;
	}

	return 0;
}
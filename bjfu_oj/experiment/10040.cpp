#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

int main()
{
	int num;

	while(cin>>num && num) {
		LinkList head = new LNode;
		LinkList ptr = head;

		while(num--) {
			LNode *p = new LNode;
			cin >> p->data;
			p->next = NULL;
			ptr->next = p;
			ptr = ptr->next;
		}

		LinkList odd = head->next; //奇数结点
		LinkList p1 = odd;
		head = head->next;

		LinkList even = head->next;  //偶数结点
		LinkList p2 = even;
		head = even->next;

		while(head) {
			// cout << "next " << endl;

			if(p1->next == p2) {
				// cout << "ji " << head->data << endl; 
				p1->next = head;
				p1 = head;
			} else {
				// cout << "ou " << head->data << endl;
				p2->next = head;
				p2 = head;
			}

			head = head->next;
		}

		p1->next = NULL;
		p2->next = NULL;

		while(odd) {
			cout << odd->data << " ";
			odd = odd->next;
		}
		while(even->next) {
			cout << even->data << " ";
			even = even->next;
		}
		cout << even->data << endl;
	}
	return 0;
}

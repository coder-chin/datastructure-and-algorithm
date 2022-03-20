#include <iostream>
#include <vector>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *LinkList;

void createLink(LinkList &L, int m) {
	L = new LNode;
	L->next = NULL;
	LinkList prt = L;

	for (int i = 0; i < m; ++i)
	{
		LNode* node = new LNode;
		cin >> node->data;
		node->next = NULL;
		prt->next = node;
		prt = prt->next;
	}
}

void move(LinkList &L, int dis, int num) {
	LinkList head = L;
	LinkList tail = L;

	while(tail->next) {
		tail = tail->next;  //到达尾节点
	}

	for (int i = 0; i < num-dis; ++i)
	{
		head = head->next;
	}

	LinkList newHead = head->next;
	head->next = NULL;

	tail->next = L->next;


	L->next = newHead;       //新节点搞定
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
	int num, dis;

	while(cin>>num && num) {
		LinkList L;
		createLink(L, num);
		cin >> dis;

		dis = dis%num;
		if(dis) {
			move(L, dis%num, num);
		}
		
		printNode(L);
	}

	return 0;
}
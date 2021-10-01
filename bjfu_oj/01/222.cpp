#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0

int length;
int flag;

typedef struct {
	string no;
	string name;
	double price;
} Book;

typedef struct LNode {
	Book book;
	struct LNode *next;
} LNode, *LinkList;

bool init(LinkList L) {
	L->next = NULL;
	return OK;
}

bool input(LinkList L) {
	cin >> length;
	int i = length;

	LNode *p = L;
	string no, name;
	double price;

	while(i) {
		cin >> no >> name >> price;
		LNode *q = new LNode;
		q->book.no = no;
		q->book.name = name;
		q->book.price = price;
		i--;
		p->next = q;
		p = p->next;
	}

	return OK;
}

bool deleteNode(LinkList L) {
	int pos;
	cin >> pos;

	if(pos<1 || pos>length) {
		cout << "Sorry，the position to be deleted is invalid!" << endl;
		flag = 1;
		return ERROR;
	}

	LinkList p = L->next;
	for(int i=1; i<pos-1; i++) {
		p = p->next;
	}
	p->next = p->next->next;
	return OK;
}

bool output(LinkList L) {
	LinkList p = L->next;
	while(p) {
		cout << p->book.no << " " << p->book.name << " " << fixed <<  setprecision(2) << p->book.price << endl;
		p = p->next;
	}
	return OK;
}


int main()
{
	LinkList L = new LNode;
	init(L);
	input(L);
	deleteNode(L);
	if(flag) return 0;
	output(L);
	return 0;
}
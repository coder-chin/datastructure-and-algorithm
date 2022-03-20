#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0

int length = 0;
int flag = 1;

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
	LNode *p = L;
	string no, name;
	double price;
	int i = length;
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

bool insert(LinkList L) {
	LinkList p = L;
	int pos;
	cin >> pos;

	if(pos<1 || pos>length+1) {
		cout << "Sorry，the position to be inserted is invalid!" << endl;
		flag = 0;
	}
	if(!flag) return ERROR;

	string no, name;
	double price;
	cin >> no >> name >> price;
	LNode *n = new LNode;
	n->book.no = no;
	n->book.name = name;
	n->book.price = price;
	for(int i=0; i<pos-1; i++) {
		p = p->next;
	}
	n->next = p->next;
	p->next = n;

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
	insert(L);
	if(!flag) return 0;
	output(L);
	return 0;
}
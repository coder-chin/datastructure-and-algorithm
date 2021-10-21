#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0
int length = 0;

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

bool output(LinkList L) {
	int times, pos;
	cin >> times;
	for(int i=0; i<times; i++) {
		cin >> pos;
		if(pos<1 || pos>length) {
			cout << "Sorry，the book on the best position doesn't exist!" << endl;
			continue;
		}
		else {
			LinkList p = L;
			for(int i=0; i<pos; i++) {
				p = p->next;
			}
			cout << p->book.no << " " << p->book.name << " " << fixed <<  setprecision(2) << p->book.price << endl;
		}
	}
	return OK;
}

int main()
{
	LinkList L = new LNode;
	init(L);
	input(L);
	output(L);
	return 0;
}
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
	int times=0;
	cin >> times;

	LinkList p;
	string book;
	
	for(int i=0; i<times; i++) {
		flag = 0;
		p = L;
		cin >> book;

		while(p) {
			if(p->book.name == book) {
				flag++;
			}
			p = p->next;
		}

		if(flag) {
			cout << flag << endl;
			 p = L;
			 while(p) {
			 	if(p->book.name == book) {
			 		cout << p->book.no << " " << p->book.name << " " << fixed <<  setprecision(2) << p->book.price << endl;
			 	}
			 	p = p->next;
			 }
		}
		else {
			cout << "Sorry，there is no your favourite!" << endl;
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
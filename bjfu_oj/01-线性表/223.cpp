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
 
bool reduceRepete(LinkList L)
{
	LinkList p = L->next;
	LinkList slow = NULL;
	LinkList fast = NULL;
	
	while(p) {
		slow = p;
		fast = slow->next;
		
		while(fast) {
			if(fast->book.no==p->book.no) {
				slow->next = fast->next;
				fast = fast->next;
              	length--;
				//cout << "same" << endl;
			} else {
				slow = slow->next;
				fast = fast->next;
				//cout << "diff" << endl;
			}
		}
		//cout << "p后移" << endl;
		p = p->next;
		
	}
	return OK;
}
 
bool output(LinkList L) {
	//cout << "--------" << endl;
  	cout << length << endl;
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
	reduceRepete(L);
	output(L);
}
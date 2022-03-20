#include<iostream>
#include<string>
#include<iomanip>  //±£ÁôÁ½Î»Ð¡Êý±ØÐëÒªÓÃµ½µÄÍ·ÎÄ¼þ
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
int length = 0;

typedef struct {
	string no;
	string name;
	double price;
}Book;
typedef struct LNode{
	Book book;
	struct LNode *next; 
}LNode, *LinkList;

int Init(LinkList L)
{
	L->next = NULL;
	return OK;
}
int Input(LinkList L)
{
	LinkList p = L;
	string no, name;
	double price;
	cin >> length;
	while(length) 
	{
		LinkList q = new LNode;
		cin >> no >> name >> price;
		q->book.no = no;
		q->book.name = name;
		q->book.price = price;
		length--;
		p->next = q;
		p = p->next;
	}
	return OK;
}
int Output(LinkList L)
{
	LNode *p = L->next;  //ָ����Ԫ��� 
	double max = p->book.price;
	p = p->next;
	while(p)
	{
		max = max < p->book.price? p->book.price : max; 
		p = p->next;
	}

	p = L->next;
	int flag = 0;

	while(p) {
		if(p->book.price==max) {
			flag++;
		}
		p = p->next;
	}

	if(flag) {
		cout << flag << endl;
		p = L->next;
		while(p) {
			if(p->book.price==max) {
				cout << p->book.no << " " << p->book.name << " " << fixed <<  setprecision(2) << p->book.price << endl;
			}
			p = p->next;
		}
	}

	return OK;
}

int main()
{
	LinkList L;
	L = new LNode;
	Init(L);
	Input(L);
	Output(L);
	return 0;
}


#include<iostream>
#include<string>
#include<iomanip>  //±£ÁôÁ½Î»Ð¡Êý±ØÐëÒªÓÃµ½µÄÍ·ÎÄ¼þ
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
int length = 0;
typedef struct{
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
	string no, name;
	double price;
	cin >> length;
	int i = 0;
	while(i<8) //ͷ�巨 
	{
		LinkList q = new LNode;
		cin >> no >> name >> price;
		q->book.no = no;
		q->book.name = name;
		q->book.price = price;
		q->next = L->next;
		L->next = q;
		i++;
	}
	return OK;
}
int Output(LinkList L)
{
	LNode *p = L;  //pÖ¸ÏòÍ·½áµã
	while(p->next)
	{
		cout << p->next->book.no << " " << p->next->book.name << " " << fixed <<  setprecision(2) << p->next->book.price << endl;
		p = p->next;
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


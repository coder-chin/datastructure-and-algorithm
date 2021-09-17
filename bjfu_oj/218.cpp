#include<iostream>
#include<string>
#include<iomanip>  //卤拢脕么脕陆脦禄脨隆脢媒卤脴脨毛脪陋脫脙碌陆碌脛脥路脦脛录镁
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
	LinkList p = L;
	string no, name;
	double price;
	cin >> length;
	int i = 0;
	while(i<8) 
	{
		LinkList q = new LNode;
		cin >> no >> name >> price;
		q->book.no = no;
		q->book.name = name;
		q->book.price = price;
		i++;
		p->next = q;
		p = p->next;
	}
	return OK;
}
int Output(LinkList L)
{
	LNode *p = L->next;  //指向首元结点 
	double max = p->book.price;
	cout << max << "start" << endl;
	p = p->next; //指向第二个
	while(p)
	{
		max < p->book.price? p->book.price : max; 
		p = p->next;
	}
	cout << max << "end" <<endl;
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


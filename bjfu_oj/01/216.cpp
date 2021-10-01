#include<iostream>
#include<string>
#include<iomanip>  //保留两位小数必须要用到的头文件
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
double sum = 0;
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
	LNode *p;
	p = L;
	string no, name;
	double price;
	while(cin>>no>>name>>price)
	{
		if(no=="0"&&name=="0"&&price==0)
			break;
		else
		{
			LinkList q = new LNode;
			q->book.no = no;
			q->book.name = name;
			q->book.price = price;
			p->next = q;
			p = q;
			sum += price;
			length++;
		}
	}
	return OK;
}
int change(LinkList L)
{
	double average = sum/length;
	cout << fixed <<  setprecision(2)  << average << endl;
	LNode *p = L->next; //指向首节点 
	while(p)
	{	
		if(p->book.price<average)
			p->book.price*=1.2;
		else 
			p->book.price*=1.1;
		p = p->next; 
	}
	return OK;
}
int Output(LinkList L)
{
	LNode *p = L;  //p指向头结点
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
	change(L);
	Output(L);
	return 0;
}


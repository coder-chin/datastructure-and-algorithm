#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef struct{
	string no;
	string name;
	double price;
}Book;
typedef struct{
	Book *elem;
	int length;
	double sum;
	double average;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);
	L.length = 0;
	L.sum = 0;
	L.average = 0;
	return OK;
}
int Input(SqList &L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
		L.sum += L.elem[i].price;
		if(L.elem[i].no=="0" && L.elem[i].name=="0" && L.elem[i].price==0)
			return OK;
		else 
			L.length++;
	}
	return OK;
}
int ChangePrice(SqList &L)
{
	L.average = L.sum/L.length;
	for (int i = 0; i < L.length; i++)
	{
		if(L.elem[i].price<L.average) L.elem[i].price *= 1.2;
		else L.elem[i].price *= 1.1;
	}
	return OK;
}
int Output(SqList &L)
{
	cout << fixed << setprecision(2) <<L.average << endl;
	for (int i = 0; i < L.length; ++i)
		cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2)
		<< L.elem[i].price << endl;
	return OK;
}

int main()
{
	SqList L;
	Init(L);
	Input(L);
	ChangePrice(L);
	Output(L);
	return 0;
}

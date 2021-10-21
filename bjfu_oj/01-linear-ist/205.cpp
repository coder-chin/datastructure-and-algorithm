#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000

typedef struct{
	string no;
	string name;
	double price;
}Book;
typedef struct{
	Book *elem;
	int length;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);
	L.length = 0;
	return OK;
}
int Input(SqList &L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
		if(L.elem[i].no=="0" && L.elem[i].name=="0" && L.elem[i].price==0)
			return OK;
		else 
			L.length++;
	}
	return OK;
}

int Sort(SqList &L)
{
	Book tmp;
	for (int i = 0; i < L.length-1; i++) //比较次数
		for (int j = 0; j < L.length-i-1; j++)
			if(L.elem[j].price<L.elem[j+1].price)
			{
				tmp = L.elem[j];
				L.elem[j] = L.elem[j+1];
				L.elem[j+1] = tmp;
			}
	return OK;
}

int Output(SqList &L)
{
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
	Sort(L);
	Output(L);
	return 0;
}

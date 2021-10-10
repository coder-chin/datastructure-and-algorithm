#include<iostream>
#include<string>
#include<iomanip>  //保留两位小数必须要用到的头文件
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
} SqList;

int initSqList(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	return OK;
}

int inputList(SqList &L)
{
	cin >> L.length;
	for (int i = 1; i <= L.length; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
	}
	return OK;
}

int outputList(SqList &L)
{
	double max = L.elem[0].price;
	int n=0;

	for (int i = 1; i < L.length; ++i)
	{
		max = max>L.elem[i].price? max : L.elem[i].price;
	}
	for (int i = 1; i <= L.length; ++i)
	{
		if(max==L.elem[i].price)
			n++;
	}
	cout << n << endl;
	for (int i = 1; i <= L.length; ++i)
	{
		if(L.elem[i].price==max)
			cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2) << L.elem[i].price << endl;
	}
	
	return OK;
}

int main()
{
	SqList L;

	initSqList(L);
	inputList(L);
	outputList(L);
	return 0;
}
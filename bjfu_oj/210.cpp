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
	int times;
	int *toSeek;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	L.times = 0;
	L.toSeek = new int[MAXSIZE];
	return OK;
}
int Input(SqList &L)
{
	cin >> L.length;
	for (int i = 1; i <= L.length; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
	}
	cin >> L.times;
	for (int i = 0; i < L.times; ++i)
	{
		cin >> L.toSeek[i];
	}
	return OK;
}
int Output(SqList &L)
{
	int index;
	for (int i = 0; i < L.times; i++)
	{
		index = L.toSeek[i];
		if(!index) cout << "Sorry，the book on the best position doesn't exist!" << endl;
		else cout << L.elem[index].no << " " << L.elem[index].name << " " << fixed << setprecision(2) << L.elem[index].price << endl;
	}
	return OK;
}

int main()
{
	SqList L;
	Init(L);
	Input(L);
	Output(L);
	return 0;
}
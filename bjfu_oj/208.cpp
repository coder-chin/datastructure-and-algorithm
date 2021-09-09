#include<iostream>
#include<string>
#include<iomanip>  //保留两位小数必须要用到的头文件
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
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	return OK;
}
int Input(SqList &L)
{
	cin >> L.length;
	for (int i = 1; i <= L.length; i++)
	{
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
	}
	return OK;
}
int Output(SqList &L)
{
	for (int i = L.length; i >= 1; i--)
		cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2)
		<< L.elem[i].price << endl;
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
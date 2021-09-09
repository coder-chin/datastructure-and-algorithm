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
	int deleteIndex;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	L.deleteIndex = 0;
	return OK;
}
int Input(SqList &L)
{
	cin >> L.length;
	for (int i = 0; i < L.length; i++)
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;

	cin >> L.deleteIndex;
	
	return OK;
}
int Delete(SqList &L)
{
	for(int i=L.deleteIndex; i<L.length;i++)
	{
		L.elem[i-1].no = L.elem[i].no;
		L.elem[i-1].name = L.elem[i].name;
		L.elem[i-1].price = L.elem[i].price;
	}

	L.length--;

	return OK;
}
int Output(SqList &L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i].no << " " << L.elem[i].name << " " << fixed << setprecision(2) << L.elem[i].price << endl;
	}
	return OK;
}

int main()
{
	SqList L;
	Init(L);
	Input(L);
	if(L.deleteIndex==0 || L.deleteIndex>=L.length)
	{
		cout << "Sorry，the position to be deleted is invalid!";
		return 0;
	}
	Delete(L);
	Output(L);
	return 0;
}
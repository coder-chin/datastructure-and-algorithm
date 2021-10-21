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
	Book book;
	int insertIndex;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	L.insertIndex = 0;
	return OK;
}
int Input(SqList &L)
{
	cin >> L.length;
	for (int i = 0; i < L.length; i++)
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;

	cin >> L.insertIndex;
	cin >> L.book.no >> L.book.name >> L.book.price;
	
	return OK;
}
int Insert(SqList &L)
{
	if(L.insertIndex != L.length+1)
		for(int i=L.length; i>=L.insertIndex;i--)
		{
			L.elem[i].no = L.elem[i-1].no;
			L.elem[i].name = L.elem[i-1].name;
			L.elem[i].price = L.elem[i-1].price;
		}
		
	L.elem[L.insertIndex-1].no = L.book.no;
	L.elem[L.insertIndex-1].name = L.book.name;
	L.elem[L.insertIndex-1].price = L.book.price;

	L.length++;

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
	if(L.insertIndex==0 || L.insertIndex>L.length+1) {
		cout << "Sorry，the position to be inserted is invalid!";
		return 0;
	}	
	Insert(L);
	Output(L);
	return 0;
}
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
	for (int i = 0; i < L.length; i++)
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].price;
	
	return OK;
}
int Output(SqList &L)
{
	SqList sta;
	Init(sta);
	sta.elem[0] = L.elem[0];
	sta.length = 1;
	int flag;

	for (int i = 1; i < L.length; i++)
	{
		flag = 1;
		for (int j = 0; j < sta.length; j++)
		{
			if(L.elem[i].no==sta.elem[j].no)
				{
					flag = 0;
					break;
				}
		}
		if(flag)
		{
			sta.elem[sta.length] = L.elem[i];
			sta.length++;
		}	
	}
	cout << sta.length << endl;
	for (int i = 0; i < sta.length; ++i)
	{
		cout << sta.elem[i].no << " " << sta.elem[i].name << " " << fixed << setprecision(2) << sta.elem[i].price << endl;
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
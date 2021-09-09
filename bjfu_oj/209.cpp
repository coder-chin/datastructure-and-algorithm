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
	string *toSeek;
}SqList;

int Init(SqList &L)
{
	L.elem = new Book[MAXSIZE];
	if(!L.elem)   exit(OVERFLOW);  //异常处理
	L.length = 0;
	L.times = 0;
	L.toSeek = new string[MAXSIZE];
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
	int num;
	for (int i = 0; i < L.times; i++)
	{
		num=0;
		for (int j = 1; j <= L.length; j++)
		{
			if(L.toSeek[i]==L.elem[j].name)
				num++;
		}
		if(num){
			cout << num << endl;
			for (int k = 1; k <= L.length; ++k)
				if(L.toSeek[i]==L.elem[k].name)
					cout << L.elem[k].no << " " << L.elem[k].name << " " << fixed << setprecision(2) << L.elem[k].price << endl;
		}
		else
			cout << "Sorry，there is no your favourite!" << endl;
		
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
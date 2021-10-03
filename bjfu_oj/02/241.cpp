#include <iostream>
using namespace std;

typedef struct
{
	int *left, *left_top, *right, *right_top;   //栈顶和栈底指针
	int m;                	 //栈最大可容纳元素个数
} DblStack;

void init(DblStack &s, int m, int n)
{
	s.left = new int[s.m]; 	//left指向这段空间
	s.left_top = s.left;     //指向0
	s.right = s.left+s.m-1;    //指向最后一个
	s.right_top = s.right; 		//也指向最后一个
	
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		*s.left_top = x;
		s.left_top++;   //注意这里实际上已经指向下一个了
	}
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		*s.right_top = x;
		s.right_top--;
	}
}

void pop(DblStack &s, int m, int n, int x, int y)
{
	for (int i = 0; i < m; ++i)
	{
		s.left_top--;
		cout << *s.left_top << " ";
	}

	if(m<x) 
		cout << 1 << endl;

	else cout << 0 << endl;

	for (int i = 0; i < n; ++i)
	{
		s.right_top++;
		cout << *s.right_top << " ";
	}
	if(n<y)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int main()
{
	int m, e0, e1, d0, d1;
	while(cin >> m)
	{
		if(m==0)
			break;

		cin >> e0 >> e1 >> d0 >> d1;
		DblStack s;
		s.m = m;

		init(s, e0, e1);

		if(e0+e1<m)
			cout << 0 << endl;
		else 
			cout << 1 << endl;

		pop(s, d0, d1, e0, e1);



	}
	return 0;
}
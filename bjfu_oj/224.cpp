#include <iostream>
#include <string>
using namespace std;

typedef struct PNode
{
	int m;
	int n;
	struct PNode* next;
}*Polynomial, PNode;

bool initPolynomial(Polynomial &L, int n)
{
	L->next = NULL;

	for(int i=0; i<n; i++) {
		PNode* s = new PNode;
		cin >> s->m >> s->n;  //每项的系数和次幂

		// 先输入，再插入

		PNode* begin = L;		  //头结点
		PNode* end = L->next; //首元结点
		while(end && s->n < end->n) {
			//系数小
			begin = begin->next;
			end = end->next;
		}
		s->next = end;
		begin->next = s;
	}

	return true;
}

Polynomial add(Polynomial L1, Polynomial L2)
{
	Polynomial ret = new PNode;
	ret->next = NULL;
	Polynomial L3 = ret;  //待返回的新链表

	PNode *p1 = L1->next;
	PNode *p2 = L2->next;

	while(p1 && p2)
	{
		if(p1->n==p2->n) {
			int sum = p1->m + p2->m;
			if(sum) {
				p1->m = sum;
				ret->next = p1;
				ret = ret->next;	
			}
			p1 = p1->next;
			p2 = p2->next;
			//cout << "0" << endl;
		}
		else if(p1->n > p2->n) {
			ret->next = p1;
			ret = ret->next;
			p1 = p1->next;
			//cout << "1" << endl;
		}
		else {
			ret->next = p2;
			ret = ret->next;
			p2 = p2->next;
			//cout << "2" << endl;
		}
	}
	ret->next = p1 ? p1 : p2;
	
	return L3;
}

Polynomial minu(Polynomial L1, Polynomial L2) 
{
	Polynomial p = new PNode;
	p->next = L2->next;

	while(p) {
		p->m *= -1;   //数据域都*-1
		p = p->next;
	}

	return add(L1, L2);
}

Polynomial mul(Polynomial L1, Polynomial L2)
{
	PNode *p1 = L1->next;
	PNode *p2 = L2->next;

	Polynomial ret = new PNode,tmp = new PNode;
	ret->next = NULL;
	tmp->next = NULL;

	while(p1) {
		while(p2) {
			PNode *t = new PNode;
			t->next = NULL;
			t->m = p1->m * p2->m;
			t->n = p1->n + p2->n;

			tmp->next = t;
			p2 = p2->next;
			ret = add(ret, tmp);
		}
		p1 = p1->next;
		p2 = L2->next;
	}

	return ret;
}

Polynomial diff(Polynomial L)
{
	Polynomial ret = L->next;
	Polynomial tmp = NULL;

	while(ret) {
		ret->m *= ret->n;
		ret->n--;
		if(ret->n < 0)
		{
			tmp = ret;
			ret = ret->next;
			delete tmp;
		}
		else {
			ret = ret->next;
		}
	}
	return L;
}

void outputPolynomial(Polynomial L)
{
	if (!L || !L->next) {
		cout << 0 << endl;
		return;
	}

	PNode* p = L->next;
	while (p)
	{
		//第一个不用输出符号
		if (p == L->next) {
			if (p->n != 0)
				cout << p->m << "x^" << p->n;
			else
				cout << p->m;
		}
		else {
			if (p->m > 0)  cout << "+";
			if (p->n != 0)
				cout << p->m << "x^" << p->n;
			else
				cout << p->m;
		}
		p = p->next;	
	}
	cout << endl;
}

int main()
{
	int cnt;  // 运算次数
	cin >> cnt;

	while(cnt--) {
		int a, b;  //a,b多项式的项数
		cin >> a >> b;

		Polynomial L1 = new PNode, L2 = new PNode;
		initPolynomial(L1, a);  	//初始化a多项式
		initPolynomial(L2, b);		//初始化b多项式

		string s;
		cin >> s;

		if(s=="+") {
			outputPolynomial(add(L1, L2));
		}
			

		else if(s=="-") 
			outputPolynomial(minu(L1, L2));

		else if(s=="*") 
			outputPolynomial(mul(L1, L2));
			

		else if(s=="'")
		{
			outputPolynomial(diff(L1));
			outputPolynomial(diff(L2));
		}
	}

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

typedef struct PNode
{
	int m;
	int n;
	struct PNode* next;
}*Polynomial, PNode;

bool createPolynomial(Polynomial L, int n)
{
	L = new PNode;
	L->next = NULL;

	for(int i=0; i<n; i++) {
		PNode* s = new PNode;
		cin >> s->m >> s->n;  //每项的系数和次幂
		PNode* pre = L;
		PNode* cur = L->next; //首元结点
		while(cur && s->n < cur->n) {
			//系数小
			pre = cur;
			cur = cur->next;
		}
		s->next = cur;
		pre->next = s;
	}
}

Polynomial add(Polynomial L1, Polynomial L2)
{
	
}

int main()
{
	int cnt; // ab运算次数
	cin >> cnt;
	while(T--) {
		int a, b;  //a,b多项式的项数
		cin >> a >> b;
		Polynomial L1, L2;
		createPolynomial(L1, a);  //初始化a多项式
		createPolynomial(L2, b);	//初始化b多项式

		char s;
		cin >> s;

		if(s=='+') outputPolynomial(add(L1, L2));
		else if(s=='-') minus(L1, L2);
		else if(s=='*') mul(L1, L2);
		else(s=='\'') {
			diff(L1);
			diff(L2);
		}
	}

	return 0;
}
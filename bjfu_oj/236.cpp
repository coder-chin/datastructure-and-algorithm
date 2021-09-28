#include <iostream>
#include <cmath>
using namespace std;

typedef struct LNode {
	int num;
	struct LNode *pre;
	struct LNode *next;
}LNode, *LinkList;

void init(LinkList L, int cnt)
{
	int tmp = 0;
	LNode *ptr = L;

	for(int i=1; i<=cnt; i++)
	{
		LNode *node = new LNode;
		cin >> tmp;
		node->num = tmp;
		ptr->next = node;
		node->pre = ptr;
		ptr = ptr->next;
	}
	ptr->next = NULL;
}

void reduceRepete(LinkList L)
{
	LNode *slow = L->next;
	LNode *fast = NULL;

	while(slow->next) {  
		fast = slow->next;

		while(fast->next)
		{
			if(abs(slow->num)==abs(fast->num)){
				fast->pre->next = fast->next;
				fast->next->pre = fast->pre; 
				fast = fast->next;
			}
			else{
				fast = fast->next;
			}
		}
	
		if(abs(slow->num)==abs(fast->num)) {
			fast->pre->next = NULL;
		}
		
		if(slow->next) {
			slow = slow->next;
		}
	}
}

void output(LinkList L)
{
	L = L->next;
	while(L->next)
	{
		cout << L->num << " ";
		L = L->next;
	}
	cout << L->num;
	cout << endl;
}

int main()
{
	int cnt;
	while(cin>>cnt)
	{
		if(!cnt) break;

		LNode *L = new LNode;
		init(L, cnt);
		reduceRepete(L);
		output(L);
	}
	return 0;
}
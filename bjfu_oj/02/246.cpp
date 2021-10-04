#include <iostream>
using namespace std;

typedef struct QNode{
	int data;
	struct QNode* next;  // 注意写法
}QNode, *Queue;

void init(Queue& Q)
{
	Q->next = Q;
}

void push(Queue& Q, int m)
{
	QNode* q = new QNode;
	q->data = m;
	q->next = Q->next;
	Q->next = q;
	Q = q;
	//cout << Q->data << endl;
}

void pop(Queue& Q) {
	Queue top = Q->next->next; // 首元节点
	cout << top->data << " ";
	Q->next->next = top->next; //跳过该节点
	if(Q==top)  //只有一个节点
		Q = Q->next;
	delete top;
}

bool isEmpty(Queue& Q)
{
	if(Q->next==Q)
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	while(cin>>n>>m && m && n)
	{
		Queue Q = new QNode;
		init(Q);
		while(n--) {
			int tmp;
			cin >> tmp;
			push(Q, tmp);
		}
		while(m--) {
			pop(Q);
		}

		if(isEmpty(Q))
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

	return 0;	
}
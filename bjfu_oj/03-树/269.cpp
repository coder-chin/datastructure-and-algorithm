#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int length, i;
char path[100];

void createBiTree(BiTree &t, string s, int &i) {
	if(s[i]=='0') {
		t = NULL;
	} else {
		t = new BiTNode;
		t->data = s[i];
		createBiTree(t->lchild, s, ++i);
		createBiTree(t->rchild, s, ++i);
	}
}

void preTraverse(BiTree t) {
	if(t) {
		cout << t->data;
		preTraverse(t->lchild);
		preTraverse(t->rchild);
	}
}

void inTraverse(BiTree t) {
	if(t) {
		inTraverse(t->lchild);
		cout << t->data;
		inTraverse(t->rchild);
	}
}

void postTraverse(BiTree t) {
	if(t) {
		postTraverse(t->lchild);
		postTraverse(t->rchild);
		cout << t->data;
	}
}
    
int main()
{
	string s;

	while(cin>>s && s!="0")
	{

		BiTree t = NULL;
		i = -1;
		length = 0;

		createBiTree(t, s, ++i);
		preTraverse(t);
		cout << endl;
		inTraverse(t);
		cout << endl;
		postTraverse(t);
		cout << endl;
	}

	return 0;
}
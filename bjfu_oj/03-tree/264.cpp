#include <iostream>
#include <string>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void createBiTree(BiTree &t, string s, int& length) {
	if(s[length]=='0') {
		t = NULL;
	}

	else {
		t = new BiTNode;
		t->data = s[length];
		createBiTree(t->lchild, s, ++length);
		createBiTree(t->rchild, s, ++length);
	}
} 

void swapBiTree(BiTree t) {
	if(t) {
		if(t->lchild && t->rchild) {
			BiTree tmp = t->lchild;
			t->lchild = t->rchild;
			t->rchild = tmp;
		} else if(t->lchild) {
			t->rchild = t->lchild;
			t->lchild = NULL;
		} else {
			t->lchild = t->rchild;
			t->rchild = NULL;
		}

		swapBiTree(t->lchild);
		swapBiTree(t->rchild);
	}
}

void outputBiTree(BiTree t) {
	if(t) {
		cout << t->data;
		outputBiTree(t->lchild);
		outputBiTree(t->rchild);
	}
}

int main()
{
	string s;

	while(cin>>s && s != "0") {
		BiTree t;

		int i=-1;

		createBiTree(t, s, ++i);
		swapBiTree(t);
		outputBiTree(t);
		cout << endl;
	}

	return 0;
}
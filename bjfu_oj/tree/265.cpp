#include <iostream>
#include <string>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int i;

void createBiTree(BiTree &t, string s, int &i) {
	// cout << i << endl;
	if(s[i]=='0') {
		t = NULL;
	} else {
		t = new BiTNode;
		t->data = s[i];
		createBiTree(t->lchild, s, ++i);
		createBiTree(t->rchild, s, ++i);
	}
}

void visitBiTree(BiTree t) {
	if(t) {
		// cout << "jump" << endl;
		cout << t->data;
		visitBiTree(t->lchild);
		cout << t->data;
		visitBiTree(t->rchild);
	}
	
}

int main()
{
	string s;

	while(cin>>s && s!="0")
	{
		BiTree t = NULL;
		i = -1;
		createBiTree(t, s, ++i);
		
		visitBiTree(t);
		
		cout << endl;
	}

	return 0;
}
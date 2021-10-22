#include <iostream>
#include <string>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

bool flag;

void createBiTree(BiTree &t, string s, int &i) {
	if(s[i]=='#') {
		// cout << i << endl;
		t = NULL;
	} else {
		t = new BiTNode;
		t->data = s[i];
		createBiTree(t->lchild, s, ++i);
		createBiTree(t->rchild, s, ++i);
	}
}

void judge(BiTree &t) {
	if(t) {
		if(t->lchild && !t->rchild) {
			if(t->data < t->lchild->data) {
				flag = 0; return;
			}
		}
		else if(t->rchild && !t->lchild) {
			if(t->data > t->lchild->data) {
				flag = 0; return;
			}
		}
		else if(t->rchild && t->lchild) {
			if(t->lchild->data < t->data && t->rchild->data > t->data) {}
			else {
				flag = 0; return;
			}
		}


		judge(t->lchild);
		judge(t->rchild);
	}

	
}

int main()
{
	string s;

	while(cin>>s && s!="#") {
		BiTree tree;
		flag = true;
		int i = 0;

		createBiTree(tree, s, i);
		judge(tree);

		if(flag) {
			cout << "YES" << endl; 
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

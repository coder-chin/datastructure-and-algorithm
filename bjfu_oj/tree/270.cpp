#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int i;
vector<int> length(3);

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

void traverseBiTree(BiTree t) {
	if(t) {
		if(t->lchild && t->rchild) {
			length[2]++;
		} else if( (!t->lchild && t->rchild) || (t->lchild && !t->rchild) ) {
			length[1]++;
		} else {
			length[0]++;
		}
		traverseBiTree(t->lchild);
		traverseBiTree(t->rchild);
	}
}
    
int main()
{
	string s;

	while(cin>>s && s!="0")
	{
		fill(length.begin(), length.end(), 0);
		BiTree t = NULL;
		i = -1;

		createBiTree(t, s, ++i);
		traverseBiTree(t);

		cout << length[0] << " " << length[1] << " " << length[2] << endl;
	}

	return 0;
}
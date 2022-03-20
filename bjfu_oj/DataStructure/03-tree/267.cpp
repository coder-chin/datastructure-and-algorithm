#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int length, i;
char ans[100];
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

void getHeight(BiTree t, int n) {
	if(t) {
		ans[n] = t->data;
		// cout << n << " " << ans[n] << endl;
		if(!t->lchild && !t->rchild) {
			if(n+1 > length) {
				length = n+1;
				for(int i=0; i<=n; i++) {
					path[i] = ans[i];
				}
			}
			
		}
		else {
			getHeight(t->lchild, n+1);
			getHeight(t->rchild, n+1);
		}
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
		
		getHeight(t, length);
		cout << length << endl;
		for(int i=0; i<length; i++) {
			cout << path[i];
		}
		cout << endl;
	}

	return 0;
}
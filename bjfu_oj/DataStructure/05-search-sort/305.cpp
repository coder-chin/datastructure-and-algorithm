#include <iostream>
#include <string>
using namespace std;
 
int flag;
 
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
 
void compare(BiTree t1, BiTree t2) {
	if( (t1&&!t2) || (!t1&&t2) ) {
		flag = 0;
	}
 
	else if(t1 && t2) {
		if(t1->data != t2->data) {
			// cout << "here" << endl;
			flag = 0;
			return ;
		} else {
			// cout << t1-> data << " and " << t2->data << endl;
			compare(t1->lchild, t2->lchild);
			compare(t1->rchild, t2->rchild);
		}
	}
}
 
int main()
{
	string s1, s2;
 
	while(cin>>s1 && s1[0]!='0') {
		cin >> s2;
 
		BiTree t1, t2;
		// cout << s1 << " " << s2 << endl;
 
		int i=-1, j=-1;
		flag = 1;
		createBiTree(t1, s1, ++i);
		createBiTree(t2, s2, ++j);
 
		compare(t1, t2);
 
		if(flag) {
			cout << "YES" << endl; 
		} else {
			cout << "NO" << endl;
		}
	}
 
	return 0;
}
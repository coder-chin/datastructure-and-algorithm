#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
 
int i, k = 0, floor=1;
vector<int> width(10000);
int maxWidth = 0; //默认第一层
int f = 1;
 
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
 
void getMaxWidth(BiTree &p) {
    if(p) {
    	f++;
    	width[f]++;
    	floor = floor < f ? f : floor;
    	getMaxWidth(p->lchild);
    	getMaxWidth(p->rchild);
    	f--;
    }
}
 
int main()
{
	string s;
 
	while(cin>>s && s!="0")
	{
		fill(width.begin(), width.end(), 0);
		maxWidth = 1;
 
		BiTree t = NULL;
		i = -1;
		createBiTree(t, s, ++i);
		
		getMaxWidth(t);
 
		for (int i = 1; i < floor; ++i)
		{
			if(maxWidth < width[i]) 
				maxWidth = width[i];
		}
		
		cout << maxWidth << endl;
	}
 
	return 0;
}
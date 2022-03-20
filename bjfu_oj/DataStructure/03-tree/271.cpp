#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int i;

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

int getMaxHeight(BiTree t) {
	vector<BiTree> queue;  //队列
 	queue.push_back(t);  //root
 	int height = 0;
	while(!queue.empty()) {
		height++;
		vector<BiTree> tmp;		//存放下一层	
		for(BiTree item: queue) {
			if(item->lchild) {
				tmp.push_back(item->lchild);
			}
			
			if(item->rchild) {
				tmp.push_back(item->rchild);
			}																				
		}
		queue = tmp;
	}

	return height;
}

int main()
{
	string s;

	while(cin>>s && s!="0")
	{
		BiTree t = NULL;
		i = -1;
		createBiTree(t, s, ++i);
		int maxHeight = getMaxHeight(t);
		
		cout << maxHeight << endl;
	}

	return 0;
}
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

int getMaxWidth(BiTree t) {
	vector<BiTree> queue;  //队列
	int maxWidth = 1;
 	queue.push_back(t);  //root

	while(!queue.empty()) {
		vector<BiTree> tmp;		//存放下一层	
		int width = 0;
		for(BiTree item: queue) {
			if(item->lchild) {
				tmp.push_back(item->lchild);
				width++;
			}
			
			if(item->rchild) {
				tmp.push_back(item->rchild);
				width++;
			}																				
		}
		// cout << "w: " << width << endl;
		maxWidth = width > maxWidth ? width : maxWidth;
		// cout << "max: " << maxWidth << endl;
		queue = tmp;
	}

	return maxWidth;
}

int main()
{
	string s;

	while(cin>>s && s!="0")
	{
		BiTree t = NULL;
		i = -1;
		createBiTree(t, s, ++i);
		int width = getMaxWidth(t);
		
		cout << width << endl;
	}

	return 0;
}
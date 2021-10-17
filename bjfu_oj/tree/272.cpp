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
	if(s[i]>='0' && s[i]=<'9') {
		
	}
}
 
int main()
{
	string s;
 
	while(cin>>s && s!="=")
	{
		BiTree t = NULL;
		i = -1;
		createBiTree(t, s, ++i);
		
	}
 
	return 0;
}
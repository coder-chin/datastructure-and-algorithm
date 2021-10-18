#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int pre(char c)
{
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else 
		return 0;
}

BiTree createBiTree(string s) {
	stack<char> optr;
	stack<BiTree> node;

	int n = s.size();
	char ch;
	int i = 0;
	
	for(int i=0; i<n; i++) {
		if(s[i]>='0' && s[i]<='9') {
//			 cout << "number " << s[i] << "  " <<endl;
			BiTree treeNode = new BiTNode;
			treeNode->lchild = NULL;
			treeNode->rchild = NULL;
			treeNode->data = s[i];

			node.push(treeNode);

		} 
		else {
			if(optr.empty() || s[i] == '(') {
//				 cout << "Ö±½Ó " << s[i] << endl;
				optr.push(s[i]);
			} 
			else if(s[i]==')') {
//				cout << "Óöµ½ÓÒÀ¨ºÅ" << endl; 
				ch = optr.top();
				optr.pop();	
				
				BiTree r = node.top();
//				cout << "ÓÒ±ß "  << r->data << endl;
				node.pop();
				BiTree l = node.top();
//				cout << "×ó±ß "  << l->data << endl;
				node.pop();

				BiTree treeNode = new BiTNode;
				treeNode->lchild = l;
				treeNode->rchild = r;
				treeNode->data = ch;
//				cout << "new " << treeNode->data << endl;
				node.push(treeNode);
				optr.pop();	
				
//				cout << "×óÀ¨ºÅ×ß" << endl; 
				}
			else {
				ch = optr.top();
				if(pre(s[i]) > pre(ch)) {
//					 cout << "ÈëÕ» " << endl;
					optr.push(s[i]);
				} else if(pre(s[i]) <= pre(ch)) {
						while(pre(s[i]) <= pre(ch)) {
//							cout << "Æ´´Õ½Úµã " << s[i] << endl;
							optr.pop();
							
							BiTree r = node.top();
//							cout << "ÓÒ±ß "  << r->data << endl;
							node.pop();
							BiTree l = node.top();
//							cout << "×ó±ß "  << l->data << endl;
							node.pop();
		
							BiTree treeNode = new BiTNode;
							treeNode->lchild = l;
							treeNode->rchild = r;
							treeNode->data = ch;
							
//							cout << "new " << treeNode->data << endl;
							
							node.push(treeNode);
							
							if(!optr.empty()) {
								ch = optr.top();		
							}
							if(optr.empty()) {
								break;
							}
						}
						optr.push(s[i]);
						
				}
			}
			}	
		}
	return node.top();
}

int getValue(int a, int b, char c)
{
	int ret;

	switch(c)
	{
		case '+': ret = a+b; break; 
		case '-': ret = a-b; break;
		case '*': ret = a*b; break;
		case '/': ret = a/b; break;
	}
	
//	cout << "ret: " << ret << endl;
	return ret;
}

int calc(BiTree t) {
	int lvalue = 0, rvalue = 0;

	if(t->lchild==NULL && t->rchild==NULL) {
		return t->data-'0';
	}

	else {
		lvalue = calc(t->lchild);
		rvalue = calc(t->rchild);
	
//		cout << "left: " << lvalue;
//		cout << "right: " << rvalue;
		
		return getValue(lvalue, rvalue, t->data);
	}
}
 
 
void preTraverse(BiTree t) {
	if(t) {
		cout << t->data;
		preTraverse(t->lchild);
		preTraverse(t->rchild);
	}
}
int main()
{
	string s;
 
	while(cin>>s && s!="=")
	{
		BiTree root = createBiTree(s);
		int ret = calc(root);
//
		cout << ret << endl;

		// preTraverse(root);
	}
 
	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
#define MAX 100
 
vector<int> visited(100);
int be, en;
int flag = 0;
 
typedef struct GNode{
	int data;
	bool exist;
	struct GNode* next;
} GNode, *GList;   //单个节点
 
typedef struct {
	int vexnum;
	int arcnum;
	GList node[MAX];
} ALGraph; //图结构
 
struct {
	char ch;
	int num;
} ma[MAX]; //映射表
 
void createADL(ALGraph &gra, int m, int n) {
	gra.vexnum = m;  //dian
	gra.arcnum = n;  //bian
 
	string s;
	cin >> s;
 
	for (unsigned int i = 0; i < s.size(); ++i) {
		ma[i+1].ch = s[i];
		ma[i+1].num = i+1;
	}
 
	// 创建节点
	for (int i = 1; i <= m; ++i) {
		gra.node[i] = new GNode; 
		gra.node[i]->data = i;
		gra.node[i]->exist = true;
		gra.node[i]->next = NULL;
	}
    
    // 前插
	for (int j = 0; j < n; ++j) {
		cin >> s;
		int l, r;
 
		for (int i = 1; i <= m; ++i)
		{
			if(ma[i].ch==s[0])
				l = i;
			if(ma[i].ch==s[1])
				r = i;
		}
		
		GNode *p = new GNode;
		p->data = r;
 
		GList p1 = gra.node[l];
 
		while(p1->next) 
			p1 = p1->next;
 
		p->next = NULL;
		p1->next = p;
 
		GNode *q = new GNode;
		q->data = l;
 
		GList q1 = gra.node[r];
		while(q1->next) 
			q1 = q1->next;
 
		q->next = NULL;
		q1->next = q;
	}
}
	
void DFS(ALGraph gra, int n) {
	visited[n] = 1;
 
	if(n==en) {
		flag = 1;
		return;
	}
	GList p = gra.node[n]->next;
 
	while(p) {
		if(visited[p->data]==0) {
			DFS(gra, p->data);
		}
		p = p->next;
	}
}
 
int main()
{
	int n, m;
 
	while(cin>>m>>n && m && n) {
		flag = 0;
		fill(visited.begin(), visited.end(), 0);
		ALGraph gra;
 
		createADL(gra, m, n);
 
		string path;
		cin >> path;
 
		char a = path[0];
		char b = path[1];
 
		for (int i = 1; i <= m; ++i)
		{
			if(ma[i].ch==a)
				be = i;
			if(ma[i].ch==b)
				en = i;
		}
 
		DFS(gra, be);
 
 
		if(flag)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
 
	}
	return 0;
}
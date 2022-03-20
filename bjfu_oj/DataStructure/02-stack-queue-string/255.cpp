#include <iostream>
#define max 10
using namespace std;
 
int a[max][3];//迷宫 
int m,n;//m:出口层数 n:入口
int tag;//为输出做标记 
 
int DFS(int k)//深度搜索第k层，k:当前路口 
{
	int i,j;
	if(k==m)//到达出口 
	{
		tag=1;
		return 0;
	}
	for(i=0;i<3;i++)//遍历三个路口 
	{
		if(0!=a[k][i]&&tag!=1)//如果当前路口有通路，并且没有走过 
		{
			DFS(a[k][i]);//进入下一个路口 ，递归 
		}
	}
	return 0;	 
 } 
 
int main()
{
	while(1)
	{
	cin>>n;
	if(0==n)break;
	int i,j;
	tag=0;
	for(i=1;i<=n;i++)
		for(j=0;j<3;j++)
			cin>> a[i][j];
	cin>>m;
	//a[m][0]=1;
	DFS(1);//从第一层开始搜索 
	if(1==tag) 
		cout<<"YES"<<endl;
	else if(tag==0) 
		cout<<"NO"<<endl;
	}
	
	return 0;
}
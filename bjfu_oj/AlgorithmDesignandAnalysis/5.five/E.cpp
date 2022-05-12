#include <bits/stdc++.h>
 
using namespace std;
 
// 最小生成树
int n,m;
 
int a[10000];  
int x[100000], y[100000], dis[100000]; 
int isIn[100000];
 
int fsearch(int x);        
void a_add(int x, int y);  
bool isUn(int x, int y);
 
int main()
{
    //输入数据
    while(cin>>n>>m) {	
	    for(int i=0; i<n; i++) {
	        cin>>x[i]>>y[i]>>dis[i];
	    }
	 	
	 	if(n < m-1) {
	 		cout << -1 << endl;
	 		continue;
	 	}

	    //初始化
	    for(int i=0; i<n; i++)
	    {
	        a[i]=i;
	    }
	 
	    //将边按权值升序排列
	    for(int i=0; i<m; i++)
	    {
	        for(int j=i; j<m; j++)
	        {
	            if(dis[j]<dis[i])
	            {
	                swap(dis[j],dis[i]);
	                swap(y[j],y[i]);
	                swap(x[j],x[i]);
	            }
	        }
	    }
	 
	    //按升序遍历边，加入集合，共m条边
	    int dist=0;
	    for(int i=0; i<m; i++)
	    {
	        if(!isUn(x[i],y[i]))//若第i条边的两个顶点不连通
	        {
	            a_add(x[i],y[i]);   //将两个顶点连通
	            dist+=dis[i];   //加入这条边的边长
	        }
	        else                //若已经连通则查看下一条边
	        {
	            continue;
	        }
	    }
	 
	    cout<<dist<<endl;
    }
    
    return 0;
}
 
int fsearch(int x)   //返回并查集中x节点的根节点
{
    int f=a[x];
    while(f!=a[f])
    {
        f=a[f];
    }
    a[x]=f;
    return f;
}
 
 
void a_add(int x, int y)    //将两个顶点连通
{
    int kx=fsearch(x);
    int ky=fsearch(y);
    a[ky]=kx;
}
 
bool isUn(int x, int y)     //判断x和y两个顶点是否连通
{
    int kx=fsearch(x);
    int ky=fsearch(y);
    if(kx==ky)
    {
        return true;
    }
    else
    {
        return false;
    }
}
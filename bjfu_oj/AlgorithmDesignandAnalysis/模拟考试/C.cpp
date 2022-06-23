#include <iostream>
using namespace std;
 
int n=0;
int arr[100];
bool place(int i)		//判断能不能放置第N个皇后
{
	for(int j=0;j<i;j++)
		if(arr[j]==arr[i]||abs(arr[j]-arr[i])==abs(j-i))
			return false;
	return true;
}
int queue(int n)
{
	int solution=0;
	for(int i=0;i<n;i++)
		arr[i]=0;
	int k=1;
	while(k>=0)
	{
		while(!place(k)&&k<n)			//放置第N个皇后
			arr[k]=arr[k]+1;
		if(arr[k]<n&&k==n-1)				//排列完成一次
		{
			solution++;
			arr[k]=arr[k]+1;
		}
		else if(arr[k]<n&&k<n-1)			//排列完一个皇后
		{
			k=k+1;
			arr[k]=0;
		}
		else								//当前皇后没有合适的位置
		{
			arr[k]=0;
			k=k-1;
			arr[k]=arr[k]+1;
		}
	}
	
	return solution;
}
int main()
{
	int n;
	while(cin >> n && n)
	{
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		
		int x = queue(n);
		cout << x << endl;
	}
	
	return 0;
}
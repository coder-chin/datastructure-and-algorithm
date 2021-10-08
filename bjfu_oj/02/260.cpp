#include <iostream>
#include <vector>
using namespace std;
 
int CheckSame(int m,int n, vector<int> a) {
	int cmp;
	int i,k;

	for(i=0;i<m*n;i++)
	{
		cmp=a[i]; 
		for(k=i+1;k<m*n;k++)
			if(cmp==a[k])
			{
				return 1;
			}			
	}

	return 0;		
}
 
int main()
{
	int m, n;
	
	while(cin >> m >> n && m && n)
	{
		int i,j;
		int res=0;
		vector<int> a;
		for(i=0;i<m*n;i++) {
			cin >> j;
			a.push_back(j);
		}
				
		res=CheckSame(m, n, a);

		if(res) 
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl; 
	}
 } 
 

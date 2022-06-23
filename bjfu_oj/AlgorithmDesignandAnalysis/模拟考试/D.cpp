#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	vector<int> arr;
	int n, q, num;
 
	cin >> n >> q;
 
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		arr.push_back(num);
	}
 
	sort(arr.begin(), arr.end());
 
	for (int i = 0; i < q; ++i) {
		scanf("%d", &num);
 
		int l = 0;
	    int r = arr.size();
	    	
	    bool flag = false;
 
	    while(l <= r)
	    {
	        int m = (l + r) / 2;
	        if(arr[m] == num)
	        {
	            flag = true;
	            break;
	        }
	        if(arr[m] < num)
	            l = m + 1;
	        else
	            r = m - 1;
	    }
 
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
 
	return 0;
}

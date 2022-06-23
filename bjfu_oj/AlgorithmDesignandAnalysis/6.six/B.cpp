#include<iostream>
using namespace std;
const int maxn = 1050;
int s[maxn];  // sets
int height[maxn];
void init_set(){
   for(int i = 1; i <= maxn; i++){
        s[i] = i;
        height[i]=0;
   }
}

int find_set(int x){
    if(x != s[x]) s[x] = find_set(s[x]);   // path compression
    return s[x];
}
void union_set(int x, int y){         // merging
    x = find_set(x);
    y = find_set(y);
    if (height[x] == height[y]) {
        height[x] = height[x] + 1;      // merge, height+1
        s[y] = x;
    }
    else{ //merge the lower tree to the higher tree; the height of the higher tree doesn't change
        if (height[x] < height[y])  s[x] = y;
        else   s[y] = x;
    }
}

int main (){
    int t, n, m, x, y;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        init_set();
        for(int i = 1; i <= m; i++){
            cin >> x >> y;
            union_set(x, y);
        }

        int res = 10000;
        int tmp = 0;

        for(int i = 1; i <= n; i++)   // compute the number of sets
        {
        	tmp = 0;
        	for (int j = 1; j <= n; ++j) {
        		if(find_set(s[j]) == i) tmp++;
        	}

        	
        	if((tmp < res) && (tmp != 0)) res = tmp;
        }

        cout << res << endl;
    }
    return 0;
}
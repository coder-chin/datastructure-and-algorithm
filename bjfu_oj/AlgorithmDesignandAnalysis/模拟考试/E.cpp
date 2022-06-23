#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long int> weight;
    vector<long long int> value;
    
    long long int n, bagWeight, num;
    cin >> n >> bagWeight;

    for (int i = 0; i < n; ++i)
    {
    	cin >> num;
    	value.push_back(num);
    }
    for (int i = 0; i < n; ++i)
    {
    	cin >> num;
    	weight.push_back(num);
    }

    vector<long long int> dp(bagWeight + 1, 0);

    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    
    cout << dp[bagWeight] << endl;
}

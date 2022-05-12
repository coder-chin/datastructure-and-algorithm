#include <bits/stdc++.h>
using namespace std;

int encode(string str) {
	priority_queue<int,vector<int>,greater<int>> Q;
	vector<int> arr(10000, 0);

    for(unsigned int i=0; i < str.length();i++) {
        arr[str[i]-'a']++;
    }

    for(int i = 0;i < 26;i++)
    	if(arr[i])
        	Q.push(arr[i]);

    int s = 0;
    while(Q.size()>=2)
    {
        int l1 = Q.top();
        Q.pop();
        int l2 = Q.top();
        Q.pop();
        int x = l1 + l2;
        Q.push(x);
        s += x;
    }

    return s;
}

int main()
{
	int T;
	auto M = INT_MAX;
	string str;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> M;
		cin >> str;

		int num = encode(str);

		if(num > M) cout << "no" << endl;

		else cout << "yes" << endl;
	}

	return 0;
}

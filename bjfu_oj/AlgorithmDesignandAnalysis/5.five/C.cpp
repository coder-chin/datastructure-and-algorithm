#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
 
struct cmp
{
    bool operator()(const P p1, const P p2)
    {
        return (p1.first * p2.second) < (p2.first * p1.second);
    }
};
 
int main()
{
    int N;
    int x, y;

    while(cin >> N) {
        priority_queue<P, vector<P>, cmp> que;
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            que.push(P(x, y));
        }

        int res = 0;

        while(!que.empty()) {
            auto iterator = que.top();
            que.pop();
            res += iterator.first * iterator.second;

            int time = iterator.second;

            priority_queue<P, vector<P>, cmp> tmp = que;

            while(!tmp.empty()) {
                auto iterator = tmp.top();
                tmp.pop();
                res += iterator.first * time;
            }
        }

        cout << res << endl;
    }
}
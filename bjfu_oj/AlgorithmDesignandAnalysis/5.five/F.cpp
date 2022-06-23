#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;

const int INF = 0x3f3f3f3f;


struct Edge {
    int u, v, w;
};

vector<Edge> es;
vector<int> p;

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
// 最小生成树
int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        es.resize(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;

            es[i] = {u, v, w};
        }

        sort(es.begin(), es.end(), [](const Edge& x, const Edge& y) {
                return x.w < y.w;
        });

        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
        
        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int u = es[i].u, v = es[i].v, w = es[i].w;

            int fu = find(u);
            int fv = find(v);

            if (fu == fv) continue;
            
            cnt++; // 选了多少条边
            ret += w; // 将该边的权累加到 MST 当中

            p[fu] = fv; // 将 fu 和 fv 两个集合合并
        }

        if (cnt != n-1) printf("-1\n");
        else printf("%d\n", ret);
    }
    return 0;
}
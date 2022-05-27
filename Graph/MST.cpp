#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;

// 最小生成树，利用优先队列排序边

struct edge
{
    int l, x, y;    // 边权，端点
    edge(int l, int x, int y):l(l), x(x), y(y) {}
    bool operator < (const edge &a) const {
        return l > a.l;
    }
};

int fa[N];
priority_queue<edge> Q;

int Find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    // 初始化并查集
    for (int i = 1; i <= n + 1; i++) fa[i] = i;

    // 读入图
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        Q.push({c, a, b});
    }

    int Cnt = 1, ans;
    while (!Q.empty()) {
        edge top = Q.top();
        Q.pop();
        int fx = Find(top.x), fy = Find(top.y);
        if (fx != fy) {
            fa[fx] = fy;
            Cnt++;
            // n-1次合并(1 -> n)
            if (Cnt == n) {
                ans = top.l;    // 最小生成树一定是瓶颈生成树，当图中最大边<ans时无法连通
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
struct edge
{
    int l, x, y;
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

    for (int i = 1; i <= n + 1; i++) fa[i] = i;

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
            if (Cnt == n) {
                ans = top.l;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

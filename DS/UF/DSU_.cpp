#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

// [HNOI2009] 梦幻布丁 - 洛谷

const int N = 1e6 + 5;
vector<int> g[N];
int col[N], now[N];
int ans;

void Merge(int x, int y) {
    for (int i : g[x]) {
        if (col[i - 1] == y) ans--;
        if (col[i + 1] == y) ans--;
    }
    for (int i : g[x]) {
        col[i] = y;
        g[y].push_back(i);
    }
    g[x].clear();
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
        now[col[i]] = col[i];
        if (col[i] != col[i - 1]) ans++;
        g[col[i]].push_back(i);
    }

    int op, x, y;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (x == y) continue;
            // dsu
            if (g[now[x]].size() > g[now[y]].size()) {
                swap(now[x], now[y]);
            }
            Merge(now[x], now[y]);
        }
        else cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

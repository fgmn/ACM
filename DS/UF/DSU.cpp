#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

// 21暑假排位（一）

const int N = 1e5 + 5;

struct DSU
{
    int n, fa[N], sz[N];
    vector<pair<int, int> > f[N];   // 维护还未贡献答案的朋友关系
    map<pair<int, int>, bool> mp;   // 记录已经贡献过的朋友关系
    int ans[N];

    void Ini() { for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1; }
    int Find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = Find(fa[x]);
    }
    void Merge(int x, int y) {
        int fx = Find(x), fy = Find(y);
        // dsu
        // 两种启发合并方式 1)根据集合大小 2)根据集合当前包含的朋友关系
        // if (f[fx].size() > f[fy].size()) swap(fx, fy);
        if (sz[fx] > sz[fy]) swap(fx, fy);

        if (fx != fy) {
            fa[fx] = fy;
            sz[fy] += sz[fx];
            sz[fx] = 0;

            for (auto i : f[fx]) {
                if (mp[i]) continue;    // 若已经贡献答案则跳过
                int f1 = Find(i.first), f2 = Find(i.second);
                if (f1 == f2) {
                    ans[i.first]++, ans[i.second]++;
                    // 必定是由于此次合并引起的，相同的关系在具有更多朋友关系的块中
                    // 删除耗时较大，标记关系已经贡献答案即可
                    mp[i] = 1;
                }
                else {
                    f[fy].push_back(i);
                }
            }
        }
    }
} uf;

void solve() {
    
    int m, k;
    cin >> uf.n >> m >> k;
    uf.Ini();   // 读入n后初始化
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);  // 保证朋友关系序号小在前
        uf.f[a].push_back({a, b});
        uf.f[b].push_back({a, b});
    }

    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        uf.Merge(a, b);
    }

    int q; cin >> q;
    while (q--) {
        char c; cin >> c;
        if (c == 'T') {
            cin >> a >> b;
            uf.Merge(a, b);
        }
        else if (c == 'F') {
            cin >> a >> b;
            if (a > b) swap(a, b);
            int fa = uf.Find(a), fb = uf.Find(b);
            if (fa != fb) {
                uf.f[fa].push_back({a, b});
                uf.f[fb].push_back({a, b});
            }
            else {
                uf.ans[a]++, uf.ans[b]++;
            }
        }
        else {
            cin >> a;
            cout << uf.ans[a] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#define N 1000010
using namespace std;
using ll = long long;

/*SCC 缩点
SCC：有向图的极大强连通子图称为强连通分量
对于dfs后序，如果有两个节点u,v在后序序列中u在v前，要么u没有连向v的路径，要么u有连向v的路径，则u,v在同一SCC

算法步骤：
1）dfs在原图中确定逆后序序列
2）dfs在反图上按逆后序序列的顺序进行遍历，由起点遍历到的点即构成一个SCC
*/
vector<int> g1[N], g2[N], g[N]; // 原图、反图、缩点后图
bool vis[N];
int dfn[N], scc[N], sz[N];  // dfs后序、节点所属SCC编号，SCC大小
int cnt, tot;
int d[N];   // SCC入度

void dfs(int u) {
    vis[u] = 1;
    for (int v : g1[u]) {
        if (!vis[v]) dfs(v);
    }
    // dfs后序记录
    dfn[++cnt] = u;
}

void dfs1(int u, int c) {
    scc[u] = c; // 第c个强连通分量
    for (int v : g2[u]) {
        if (!scc[v]) dfs1(v, c);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    // 读图
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    // 在原图上dfs
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    // 按dfs逆后序在反图上dfs
    for (int i = n; i > 0; i--) {
        if (!scc[dfn[i]]) dfs1(dfn[i], ++tot);
    }

    // 完成SCC求解
    for (int i = 1; i <= n; i++) {
        sz[scc[i]]++;
        for (int j : g1[i]) {       // 对原图进行缩点
            if (scc[j] != scc[i]) { // 避免出现自环
                g[scc[i]].push_back(scc[j]);    // 为缩点后的图添边，可能重复
            }
        }
    }

    // 边去重
    for (int i = 1; i <= tot; i++) {
        sort(g[i].begin(), g[i].end());
        vector<int>::iterator newEnd;
        newEnd = unique(g[i].begin(), g[i].end());
        g[i].erase(newEnd, g[i].end());
        for (int v : g[i]) d[v]++;
    }

    // 统计入度为0的SCC
    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (!d[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
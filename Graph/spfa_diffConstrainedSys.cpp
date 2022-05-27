#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

/*
以差分约束最小(大)值问题为例：
将变量xi看成图中一个节点，对于不等式xi-xj<=ck(xj-xi>=-ck)，相当于从节点j(i)到节点i(j)连一条长度为ck(-ck)的有向边。
对于一条从j走到i的路径而言，假设其长度为C，对应不等式xi-xj>=(<=)C。在最长(短)路中可以认为j到i的距离>=(<=)C,因为这条路已经为C，最长(短)路只能更长(短)。
我们现在要求xi的最大下界(最小上界)，实际为某节点x0到xi的最长(短)路。
->转化为求解最长(短)路问题
假设起点为x0，对于当前已经求出的dis[i]，对应xi-x0>=dis[i](xi-x0<=dis[i])

存在负环：xi不存在
终点不可达：xi与x0之间没有约束关系，dis[i]= +∞
*/


// a = a - 1(前缀和)
// k == 1: cb - ca <= c
// -> cb <= ca + c
// k == 2: cb - ca >= c
// k == 3: cb - ca <= c - 1
// k == 4: cb - ca >= c + 1
// max(cn)
// 0 <= dis[i] - d[i - 1] <= 1

const int N = 1010;
int n, m;
int dis[N], cnt[N];
vector<pair<int, int> > g[N];
bool vis[N];

void spfa(int s) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dis[i] = INT32_MAX;
        cnt[i] = 0;
    }

    dis[s] = 0;
    vis[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (auto i : g[u]) {
            int v = i.first, l = i.second;
            if (dis[v] > dis[u] + l) {
                dis[v] = dis[u] + l;
                cnt[v] = cnt[u] + 1;

                if (cnt[v] >= n) {
                    cout << "impossible\n";
                    return;
                }

                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (dis[n] == INT32_MAX) {
        cout << "impossible\n";
    }
    else cout << dis[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int k, a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> k >> a >> b >> c;
        a--;
        switch (k) {
            case 1: g[a].push_back({b, c});
                    break;
            case 2: g[b].push_back({a, -c});
                    break;
            case 3: g[a].push_back({b, c - 1});
                    break;
            case 4: g[b].push_back({a, -c - 1});
                    break;
            case 5: g[a].push_back({b, c});
                    g[b].push_back({a, -c});
                    break;
        }
    }

    // 每个坑最多种1瓶酸奶
    for (int i = 1; i <= n; i++) {
        g[i - 1].push_back({i, 1});
        g[i].push_back({i - 1, 0});
    }

    spfa(0);    // dis[0] = 0
    return 0;
}
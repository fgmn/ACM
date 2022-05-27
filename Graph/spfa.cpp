#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

/*
Bellman-ford的队列优化
正确性：松弛边(u,v)时如果dis[u]已经是最短路且u在v的最短路上则松弛结束后dis[v]也是最短路
优化：松弛操作仅仅发生在最短路径前导节点中已经成功松弛过的节点上
算法的平均时间复杂度为O(km),k为小于n的小常数
负权环路(负环)：一些边被松弛次数>=n
判断方法：
1）放宽条件，判断点的入队次数
2）判断最短路边数
*/

vector<pair<int, int> > g[505];
int cnt[505], dis[505]; // cnt记录节点当前最短路径的边数
bool vis[505];          // 记录节点是否入队
int n, m, w;

void spfa(int s) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        vis[i] = cnt[i] = 0;
        dis[i] = INT32_MAX;
    }

    dis[s] = 0;
    vis[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;

        for (auto i : g[u]) {
            if (dis[i.second] > dis[u] + i.first) { // 成功松弛
                dis[i.second] = dis[u] + i.first;
                cnt[i.second] = cnt[u] + 1;
                if (cnt[i.second] >= n) {   // 最短路径边数>=n代表存在负环
                    cout << "YES\n";
                    return;
                }
                if (!vis[i.second]) {
                    vis[i.second] = 1;
                    Q.push(i.second);
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int F; cin >> F;
    while (F--) {
        
        cin >> n >> m >> w;
        
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        // 读图：s与e之间存在长度为t的路
        int s, e, t;
        for (int i = 1; i <= m; i++) {
            cin >> s >> e >> t;
            g[s].push_back({t, e});
            g[e].push_back({t, s});
        }

        for (int i = 1; i <= w; i++) {
            cin >> s >> e >> t;
            g[s].push_back({-t, e});
        }

        spfa(1);
    }

    return 0;
}
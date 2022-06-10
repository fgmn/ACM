#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename _Ty> void __(_Ty &x) {
	bool neg = false;
	unsigned c = getchar();
	for (; (c ^ 48) > 9; c = getchar()) if (c == '-') neg = true;
	for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	if (neg) x = -x;
}
template<typename _Ty> _Ty& read(_Ty &x) { __(x); return x; }
template<typename _Ty, typename ..._Tr> void read(_Ty &x, _Tr&... r) { __(x); read(r...); }

const int N = 1e5 + 5;
int O[N]; // 维护节点的主要通信对象
int cnt0, cnt1;
set<pair<int, int> > Set;   // 维护通信对

struct Edge
{
    int u, v;
    ll w;
    int t;     // t:失效时间
};

struct edge
{
    // edge(int v, int w, int t):v(v), w(w), t(t) {}
    int v;
    ll w;
    int t;
};

struct cmp
{
    bool operator() (edge a, edge b) {
        if (a.w != b.w) return a.w < b.w;   // 优先返回流量最大者
       return a.v > b.v;                    // 流量相等返回编号较小者
    }
};

struct cmp1
{
    bool operator() (Edge a, Edge b) {
        return a.t > b.t;
    }
};

priority_queue<edge, vector<edge>, cmp> pq[N];
priority_queue<Edge, vector<Edge>, cmp1 > Q; // 沙漏
vector<edge> g[N]; // 实时流量数据,t保存最近失效期
// set<int> set_[N];
map<pair<int, int>, priority_queue<int, vector<int>, greater<int>> > mp; // 节点之间流量失效期

void solve() {
    int n, m;
    // cin >> n >> m;
    read(n, m);

    cnt0 = n;

    int k, l;
    for (int i = 1; i <= m; i++) {
        // 1)处理过期流量(流量减少阶段)
        while (!Q.empty()) {
            auto top = Q.top();
            // cout << "top: " << top.u << ' ' << top.v << ' ' << top.w << ' ' << top.t << '\n';

            if (i >= top.t) {
                int x_ = min(top.u, O[top.u]), y_ = max(top.u, O[top.u]);
                if (Set.find({x_, y_}) != Set.end()) {
                    Set.erase({x_, y_});
                    cnt1--;
                }
                x_ = min(top.v, O[top.v]), y_ = max(top.v, O[top.v]);
                if (Set.find({x_, y_}) != Set.end()) {
                    Set.erase({x_, y_});
                    cnt1--;
                }

                for (auto &k : g[top.u]) {
                    if (k.v == top.v) {
                        k.w -= top.w;   // 可能两个节点之间有几股流量，此时如何更新节点之间流量失效期？
                        
                        int mu = min(top.u, top.v), mv = max(top.u, top.v);
                        while (!mp[{mu, mv}].empty()) {
                            int top_ = mp[{mu, mv}].top();
                            if (i >= top_) {
                                mp[{mu, mv}].pop();
                            }
                            else break;
                        }
                        if (mp[{mu, mv}].empty()) { // 节点之间再无流量
                            // k.t = INT32_MAX;
                            for (auto it = g[top.u].begin(); it != g[top.u].end(); it++) {
                                if (it->v == k.v) {
                                    g[top.u].erase(it);
                                    break;
                                }
                            }
                        }
                        else {
                            k.t = mp[{mu, mv}].top();
                            pq[top.u].push({top.v, k.w, k.t});
                        }
                        break;
                    }
                }
                for (auto &k : g[top.v]) {
                    if (k.v == top.u) {
                        k.w -= top.w;
                        
                        int mu = min(top.u, top.v), mv = max(top.u, top.v);

                        if (mp[{mu, mv}].empty()) {
                            // k.t = INT32_MAX;
                            for (auto it = g[top.v].begin(); it != g[top.v].end(); it++) {
                                if (it->v == k.v) {
                                    g[top.v].erase(it);
                                    break;
                                }
                            }
                        }
                        else {
                            k.t = mp[{mu, mv}].top();
                            pq[top.v].push({top.u, k.w, k.t});
                        }
                        break;
                    }
                }
                while(!pq[top.u].empty()) {
                    auto top_ = pq[top.u].top();
                    // cout << "u: " << top_.v << ' ' << top_.w << ' ' << top_.t << '\n';
                    if (top_.t <= i) pq[top.u].pop();
                    else {
                        O[top.u] = top_.v;
                        break;
                    }
                }
                while(!pq[top.v].empty()) {
                    auto top_ = pq[top.v].top();
                    // cout << "v: " << top_.v << ' ' << top_.w << ' ' << top_.t << '\n';
                    if (top_.t <= i) pq[top.v].pop();
                    else {
                        O[top.v] = top_.v;
                        break;
                    }
                }
                if (O[top.u] && pq[top.u].empty()) O[top.u] = 0, cnt0++;
                if (O[top.v] && pq[top.v].empty()) O[top.v] = 0, cnt0++;    // 原先有通信对象 -> 没有对象成为信息孤岛
                // cout << "cnt0: " << cnt0 << '\n';
                // cout << "Objects: ";
                // for (int _i = 1; _i <= n; _i++) {
                //     cout << O[_i] << ' ';
                // }
                // cout << '\n';
                if (O[O[top.u]] == top.u) {
                    x_ = min(top.u, O[top.u]), y_ = max(top.u, O[top.u]);
                    Set.insert({x_, y_});
                    cnt1++;
                }
                if (O[O[top.v]] == top.v) {
                    x_ = min(top.v, O[top.v]), y_ = max(top.v, O[top.v]);
                    if (Set.find({x_, y_}) == Set.end()) {
                        Set.insert({x_, y_});
                        cnt1++;
                    }
                }
                Q.pop();
            }
            else break;
        }

        // 2)添加k个流量并设置倒计时(流量增加阶段)
        // cin >> k;
        read(k);
        int u, v, x, y;
        for (int j = 1; j <= k; j++) {
            // cin >> u >> v >> x >> y;
            read(u); read(v); read(x); read(y);
            // read(u, v, x, y);
            int x_ = min(u, O[u]), y_ = max(u, O[u]);
            if (Set.find({x_, y_}) != Set.end()) {
                Set.erase({x_, y_});
                cnt1--;
            }
            x_ = min(v, O[v]), y_ = max(v, O[v]);
            if (Set.find({x_, y_}) != Set.end()) {
                Set.erase({x_, y_});
                cnt1--;
            }

            if(!O[u]) cnt0--;
            if(!O[v]) cnt0--;

            if (u > v) swap(u, v);

            bool FLAG = 0;
            for (auto &k :g[u]) {
                if (k.v == v) {
                    k.w += x;
                    k.t = min(k.t, i + y);  // 设置当前流量的有效期
                    pq[u].push({v, k.w, k.t});
                    FLAG = 1;
                    break;
                }
            }
            for (auto &k :g[v]) {
                if (k.v == u) {
                    k.w += x;
                    k.t = min(k.t, i + y);
                    pq[v].push({u, k.w, k.t});
                    break;
                }
            }

            if (!FLAG) {
                g[u].push_back({v, x, i + y});
                g[v].push_back({u, x, i + y});

                pq[u].push({v, x, i + y});
                pq[v].push({u, x, i + y});
            }

            // u,v主要通信对象可能变化
            while(!pq[u].empty()) {
                auto top_ = pq[u].top();
                if (top_.t <= i) pq[u].pop();
                else {
                    O[u] = top_.v;
                    break;
                }
            }
            while(!pq[v].empty()) {
                auto top_ = pq[v].top();
                if (top_.t <= i) pq[v].pop();
                else {
                    O[v] = top_.v;
                    break;
                }
            }
            if (O[O[u]] == u) {
                x_ = min(u, O[u]), y_ = max(u, O[u]);
                Set.insert({x_, y_});
                cnt1++;
            }
            if (O[O[v]] == v) {
                x_ = min(v, O[v]), y_ = max(v, O[v]);
                if (Set.find({x_, y_}) == Set.end()) {
                    Set.insert({x_, y_});
                    cnt1++;                    
                }
            }
            Q.push({u, v, x, i + y});
            mp[{u, v}].push(i + y);
        }

        // 3)回答l个通信主要对象
        // cin >> l;
        read(l);
        int o;
        for (int j = 1; j <= l; j++) {
            // cin >> o;
            read(o);
            cout << O[o] << '\n';
        }

        bool p, q;
        // cin >> p >> q;
        read(p, q);
        if (p) cout << cnt0 << '\n';
        if (q) cout << cnt1 << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    solve();
    return 0;
}

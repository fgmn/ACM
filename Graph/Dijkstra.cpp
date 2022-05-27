#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f	// ll
using namespace std;

const int Max = 1e6 + 10;
using ll = long long;

struct node {
	ll p, w;	// 另一端点、距离
};

vector<node> g[Max];
ll dis[Max];	// 单源距离
bool vis[Max];	// 是否已经松弛完
priority_queue<pair<ll, int> > pq;

map<ll, int> mp;	// 离散化：原节点编号->新编号

void Dijkstra(int st) {
	
	memset(dis, 0x3f, sizeof dis);
	
	dis[st] = 0;
	pq.push({0, st});

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		if (vis[u]) continue;	// 可能该节点已经松弛
		vis[u] = 1;
		
		int Size = g[u].size();
		for (int i = 0; i < Size; i++) {
			int cur = g[u][i].p, len = g[u][i].w;
			
			if (vis[cur] == 0 && dis[cur] > dis[u] + len) {
				dis[cur] = dis[u] + len;
				pq.push({-dis[cur], cur});	// 通过取负数的方法将大根堆转化为小根堆
			}
		}
	} 
} 

void solve() {
	ll M, Xa, Xb, S;
	cin >> M >> Xa >> Xb >> S;
	
	// 节点编号较大，离散化后跑Dijkstra

	int cnt = 0;
	mp[Xa] = ++cnt;
	if (Xa != Xb) mp[Xb] = ++cnt;
	
	ll a, b, l, w;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> l >> w;
		
		if (!mp[a]) mp[a] = ++cnt;
		if (!mp[b]) mp[b] = ++cnt;
		
		g[mp[a]].push_back({mp[b], l});
		if (w == 2) g[mp[b]].push_back({mp[a], l});
	}
	
	Dijkstra(mp[Xa]);
	
	if (dis[mp[Xb]] == INF) {
		cout << "-1\n";
	}
	else {
		ll ans = dis[mp[Xb]] / S;
		if (dis[mp[Xb]] % S) ans += 1;
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	solve();
	return 0;
}


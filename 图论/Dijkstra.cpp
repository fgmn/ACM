#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f	// ll
using namespace std;

const int Max = 1e6 + 10;
using ll = long long;

struct node {
	ll p, w;
	// 点 距离 
};

vector<node> g[Max];
ll dis[Max];
bool vis[Max];
// 单源距离 是否选择
priority_queue<pair<ll, int> > pq;

map<ll, int> mp;


void D(int st) {
	
	memset(dis, INF, sizeof dis);
	
	dis[st] = 0;
	pq.push({0, st});
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		int Size = g[u].size();
		for (int i = 0; i < Size; i++) {
			int cur = g[u][i].p, len = g[u][i].w;
			
			if (vis[cur] == 0 && dis[cur] > dis[u] + len) {
				dis[cur] = dis[u] + len;
				pq.push({-dis[cur], cur});
			}
		}
	} 
} 

void solve() {
	ll M, Xa, Xb, S;
	cin >> M >> Xa >> Xb >> S;
	
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
	
	D(mp[Xa]);
	
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


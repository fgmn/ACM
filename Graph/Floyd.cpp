#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

// floyd变形：不一定是按照1到n的次序将中间节点加入可达集合

int n, m, q;
int T[205], dis[205][205];

void Floyd(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
} 

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> q;

	// 读入节点的开放时间
	for (int i = 0; i < n; i++) {
		cin >> T[i];
	}
	
	memset(dis, inf, sizeof dis);
	
	// 读入图
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		dis[a][b] = dis[b][a] = min(w, dis[a][b]);
	}
	for (int i = 0; i < n; i++) {
		dis[i][i] = 0;
	}
	
	// 回答询问
	int k = 0;
	while (q--) {
		cin >> a >> b >> w;
		// 节点开放，加入可达集合，求解加入该节点后的最短路变化
		while (T[k] <= w && k < n) {
			Floyd(k++);
		}
		
		if (T[a] > w || T[b] > w) {
//			puts("-1");
			cout << "-1\n";
		}
		else {
			if (dis[a][b] == inf) cout << "-1\n";	// puts("-1");
			else cout << dis[a][b] << '\n';
		}
	}
	return 0;
}


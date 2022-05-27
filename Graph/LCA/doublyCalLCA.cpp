#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define pb push_back
#define lowbit(x) x &(-x)
#define mst(a, b) memset(a, b, sizeof a)
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const int Mod = 1e9 + 7;
const int N = 1e5 + 10;

int n, m;
vector<pair<int, int>> g[N];
int dep[N];
int f[N][30];
int dis[N], vis[N];
int mx;

void ini()
{
	mx = (int)(log(n) / log(2));
	mst(dep, 0);
	mst(f, -1);
	mst(dis, 0);
	mst(vis, 0);
	for (int i = 0; i <= n; i++)
		g[i].clear();
}
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;

	for (int i = 0; i <= mx; i++)
		if (f[u][i] != -1)
			f[u][i + 1] = f[f[u][i]][i];

	for (auto i : g[u])
	{
		if (i.fi == fa)
			continue;
		dis[i.fi] = dis[u] + i.se;
		f[i.fi][0] = u;
		dfs(i.fi, u);
	}
}

int LCA(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);

	for (int i = mx; i >= 0; i--)
	{
		if (f[x][i] != -1 && dep[f[x][i]] >= dep[y])
		{
			x = f[x][i];
		}
		if (x == y)
			return x;
	}

	for (int i = mx; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);

	int cas;
	cin >> cas;

	while (cas--)
	{

		cin >> n >> m;
		ini();

		int a, b, c;
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b >> c;
			vis[b] = 1;
			g[a].pb(mp(b, c));
			g[b].pb(mp(a, c));
		}

		int root;
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)
			{
				root = i;
				break;
			}

		dfs(root, 0);

		//		for(int i=1;i<4;i++) cout<<dis[i]<<' ';
		//		cout<<'\n';

		while (m--)
		{
			int a, b;
			cin >> a >> b;
			cout << dis[a] + dis[b] - 2 * dis[LCA(a, b)] << endl;
		}
	}
	return 0;
}

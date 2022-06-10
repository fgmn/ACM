#include <bits/stdc++.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
typedef long long LL;

/*struct FastIO{
	template<typename Ty>
	FastIO& operator >> (Ty& in){
		in = 0;
		char ch = getchar();
		bool flag = 0;
		for (; ! isdigit(ch); ch = getchar()) (ch == '-' && (flag = 1));
		for (; isdigit(ch); ch = getchar()) in = (in * 10) + (ch ^ 48);
		return *this;
	}
} fin;*/

const int MaxN = 210, MaxM = 5e3 + 100, inf = 0x3fffffff;
int n, m, s, t;
int to[MaxM << 1], nxt[MaxM << 1], w[MaxM << 1], dep[MaxN], head[MaxN], cnt = 1, cur[MaxN];
LL ans = 0;
bool vis[MaxN];

void add(int u, int v, int ww)
{
    ++cnt;
    w[cnt] = ww;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

// 构建分层图
bool bfs()
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
        dep[i] = inf;
        cur[i] = head[i]; // cur相当于head
    }

    vis[s] = 1;
    queue<int> q;
    q.push(s);
    dep[s] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = head[p]; i; i = nxt[i])
        {
            if (dep[to[i]] > dep[p] + 1 && w[i])
            {
                dep[to[i]] = dep[p] + 1;
                if (!vis[to[i]])
                    vis[to[i]] = 1, q.push(to[i]);
            }
        }
    }
    if (dep[t] == dep[0])
        return 0; // 无法到达 t 点
    return 1;
}

//
LL dfs(int x, int minn)
{ // minn: 目前所有弧的最小残量
    if (x == t)
    {
        ans += minn;
        return minn;
    }
    LL use = 0;
    for (int i = cur[x]; i; i = nxt[i])
    {
        cur[x] = i; // 搜过一条边后，确保这条边无法增广，直接搜索下一条有用边
        if (w[i] && dep[to[i]] == dep[x] + 1)
        {
            LL nex = dfs(to[i], min(minn - use, w[i])); //
            if (nex > 0)
            {
                use += nex;
                w[i] -= nex;
                w[i ^ 1] += nex;
                if (use == minn)
                    break;
            }
        }
    }
    return use;
}

void Dinic()
{
    while (bfs())
        dfs(s, inf);
    printf("%lld\n", ans);
}

int get()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, ww;
        cin >> u >> v >> ww;
        add(u, v, ww);
        add(v, u, 0);
    }
    Dinic();
    return 0;
}

int main()
{
    //	freopen("C:\\Users\\DELL\\Desktop\\P3376_4.in", "r", stdin);
    return get() && 0;
}

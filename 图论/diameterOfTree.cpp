#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int vis[N];
int dis[N];

struct node
{
    int w;
    int p;
} t;

vector<node> edge[N];

void dfs(int st)
{
    for (int i = 0; i < (int)edge[st].size(); i++)
    {
        t = edge[st][i];
        if (!vis[t.p])
        {
            vis[t.p] = 1;
            dis[t.p] = dis[st] + t.w;
            dfs(t.p);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n - 1; i++) // ��:n-1����
    {
        int u, v, w;
        cin >> u >> v >> w;
        t.p = v;
        t.w = w;
        edge[u].push_back(t);
        t.p = u;
        t.w = w;
        edge[v].push_back(t);
    }

    vis[0] = 1;
    dfs(0); //��0����dfsһ��

    int maxlen = 0, Q, W, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dis[i] > maxlen)
            maxlen = dis[i], Q = i;
        dis[i] = vis[i] = 0; // ���ҳ���Զ���ͬʱclear����
    }                        // �ҵ�ֱ����һ���˵�Q

    vis[Q] = 1;
    dfs(Q); // ��Q����

    for (int i = 0; i < n; i++)
        if (dis[i] > ans)
            ans = dis[i], W = i; // �ҵ���һ���˵�W��ͬʱ�õ�ֱ������

    cout << ans << endl;

    return 0;
}

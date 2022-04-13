#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 1e5 + 10;
int n;
int point[N], v[N], nxt[N], len[N], vis[N], cnt[N];
// vis[]为访问状态标记，cnt[]存到该节点最短路的边数
int dis[N]; //最短路距离

void spfa(int s)
{
	for (int i = 1; i <= n; i++)
		vis[i] = 0, dis[i] = inf, cnt[i] = 0;
	
	dis[s] = 0;
	vis[s] = 1;
	queue<int> p;
	p.push(s);

	while (!p.empty())
	{
		int now = p.front();
		p.pop();
		vis[now] = 0;
		for (int i = point[now]; i; i = nxt[i])
		{ // 链式前项星:为边编号，v[]存的是这条边能到达的点
			if (dis[v[i]] > dis[now] + len[i])
			{
				dis[v[i]] = dis[now] + len[i];
				// pre[v[i]] = now;
				cnt[v[i]] = cnt[now] + 1;

				if (cnt[v[i]] >= n)
				{
					// 存在负环
				}
				if (!vis[v[i]])
				{ // vis[]记录节点是否在队列中,防止重复入队
					vis[v[i]] = 1;
					p.push(v[i]);
				}
			}
		}	
	}
}

int main()
{
	return 0;
}

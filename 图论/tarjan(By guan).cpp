#include <bits/stdc++.h>
using namespace std;
//边总数和问题总数 
int tot1 = 0;
int tot2 = 0;

const int maxnedge = 1100000;
const int maxnquestion = 1100000;
const int maxnnode = 1100000;

int father[maxnnode]={0}, lca[maxnnode]={0}, dist[maxnnode]={0}, ansf[maxnnode]={0}, anst[maxnnode]={0};
bool vis[maxnnode]={0};

struct edge
{
	int to;
	int weight;
	int next;
} a[maxnedge];

struct question
{
	int to;
	int number;
	int next;
} b[maxnquestion];

int edge1[maxnedge];
int question1[maxnquestion];

int fa(int x)
{
	if (x == father[x])
		return x;
	return fa(father[x]);
}

void add_edge(int x, int y, int w)
{
	a[++tot1].to = y;
	a[tot1].weight = w;
	a[tot1].next = edge1[x];
	edge1[x] = tot1;
}

void add_question(int x, int y, int w)
{
	b[++tot2].to = y;
	b[tot2].number = w;
	b[tot2].next = question1[x];
	question1[x] = tot2;
}

void tarjan(int x)
{
	father[x] = x;
	vis[x] = 1;
	for (int i = question1[x]; i; i = b[i].next)
	{
		int now_to = b[i].to;
		if (vis[now_to])
		{
			lca[b[i].number] = fa(now_to);
		}
	}
	for (int i = edge1[x]; i; i = a[i].next)
	{
		int now_to = a[i].to;
		if (!vis[now_to])
		{
			dist[now_to] = dist[x] + a[i].weight;
			tarjan(now_to);
			father[now_to] = x;
		}
	}
}

int main()
{
	memset(vis, false, sizeof(vis));
	memset(edge1, 0, sizeof(edge));
	memset(question1, 0, sizeof(question));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(dist, 0, sizeof(dist));
	memset(father, 0, sizeof(father));
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int sum;
		scanf("%d", &sum);
		for (int j = 1; j <= sum; j++)
		{
			int to;
			scanf("%d", &to);
			add_edge(i, to + 1, 1);
			add_edge(to + 1, i, 1);
		}
	}
	
	int q;
	scanf("%d", &q);
	
	for (int i = 1; i <= q; i++)
	{
		int x1, x2;
		scanf("%d%d", &x1, &x2);
		add_question(x1 + 1, x2 + 1, i);
		add_question(x2 + 1, x1 + 1, i);
		ansf[i] = x1 + 1, anst[i] = x2 + 1;
	}
	
	tarjan(1);
	
	for (int i = 1; i <= q; i++)
		printf("%d\n", lca[i] - 1);//起点为0 
		
	return 0;
}




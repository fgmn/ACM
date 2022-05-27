#include <iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 10;

// 拓扑排序

int n;
int in_deg[N]; // 维护节点的入度
vector<int> g[N];

char c[5] = {'A', 'B', 'C', 'D', 'E'};

bool toposort()
{
	queue<int> q;	// 按照一定次序输出考虑优先队列
	// 将入度为0的点加入队列
	for (int i = 0; i < n; i++)
	{
		if (in_deg[i] == 0)
			q.push(i);
	}
	vector<int> ans;	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		ans.push_back(u);
		for (auto v : g[u])
		{
			// 若当前点的入度减为0，偏序关系大于它的点已加入拓扑序中，将它加入队列中
			if (--in_deg[v] == 0)
				q.push(v);
		}
	}

	// 若存在点未加入拓扑序中则代表不是DAG图
	if ((int)ans.size() == n)
	{
		for (int i = 0; i < n; i++)
			std::cout << c[ans[i]];
		return true;
	}
	else
		return false;
}

int main()
{
	n = 5;
	int t = 5;
	string s;
	while (t--)
	{
		cin >> s;
		if (s[1] == '<')
		{
			g[s[0] - 'A'].push_back(s[2] - 'A');
			in_deg[s[2] - 'A']++;
		}
		else
		{
			g[s[2] - 'A'].push_back(s[0] - 'A');
			in_deg[s[0] - 'A']++;
		}
	}
	// 判断n个点之间是否存在拓扑序（DAG）
	if (!toposort())
	{
		cout << "impossible" << endl;
	}

	return 0;
}

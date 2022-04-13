#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n;
int in_deg[N]; // 维护节点的入度
vector<int> g[N];

char c[5] = {'A', 'B', 'C', 'D', 'E'};

bool toposort()
{
	queue<int> q;
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
			if (--in_deg[v] == 0)
				q.push(v);
		}
	}

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
	if (!toposort())
	{
		cout << "impossible" << endl;
	}

	return 0;
}

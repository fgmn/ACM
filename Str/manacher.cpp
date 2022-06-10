#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s, c;
int r[(int)1e5 + 10];

void manacher()
{
	for (int i = 0; i < n; i++)
		c[i << 1] = '#', c[i << 1 | 1] = s[i];
	int pos = 0, maxr = 0; // pos:最长回文子串的对称轴处 maxr=r[pos]+pos
	int len = 2 * n + 1;
	c[len - 1] = '#';

	for (int i = 0; i < len; i++)
	{
		if (i < maxr)
			r[i] = min(maxr - i, r[pos * 2 - 1]);
		else
			r[i] = 0;
		// 当前最大匹配半径是r[i]
		while (i + r[i] + 1 < len && i - r[i] - 1 >= 0 && c[i + r[i] + 1] == c[i - r[i] - 1])
			r[i]++;
		if (i + r[i] > maxr)
		{
			maxr = r[i] + i;
			pos = i;
		}
	}

	for (int i = 0; i < len; i++)
		ans = max(ans, r[i]);
}

int main()
{

	manacher();

	return 0;
}

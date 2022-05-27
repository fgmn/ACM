#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

int A[maxn], T[maxn]; // T[]Ϊ�����ռ�
bool vis[maxn], vis2[maxn];

long long int cnt = 0; //����Ը���

void merge_sort(int x, int y)
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;

		merge_sort(x, m);
		merge_sort(m, y);

		while (p < m || q < y)
		{
			if (q == y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];
			else
			{
				T[i++] = A[q++];
				cnt += m - p;
			}
		}
		for (i = x; i < y; i++)
			A[i] = T[i];
	}
}

int main()
{

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	memset(vis, 0, sizeof vis);
	memset(vis2, 0, sizeof vis2);

	ll ans = 0;

	//�ȵ�����һ��������������Ը���
	for (int i = 0; i < n; i++)
	{
		if (vis[A[i] + 1] && (!vis2[A[i]]) && (!vis2[A[i] + 1]))
		{
			ans++;
			vis2[A[i]] = 1;
			vis2[A[i] + 1] = 1;
		}

		vis[A[i]] = 1;
	}

	merge_sort(0, n);
	cnt -= ans;
	//	cout<<ans<<endl;

	printf("%lld\n", cnt);

	return 0;
}

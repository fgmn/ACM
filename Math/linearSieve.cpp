#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8;

bool is_prime[maxn];
int prime[maxn];
int cnt;

void sieve(int n)
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
			prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			is_prime[i * prime[j]] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main()
{
	freopen("outt.txt", "w", stdout);

	int n;
	n = 1e6;
	sieve(n);
	for (int i = 1; i <= cnt; i++)
	{
		cout << prime[i] << '\n';
	}
	return 0;
}

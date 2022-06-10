#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 米勒-拉宾素性检验
// 二次剩余
// _int128

ll qpow(ll a, ll n, ll p)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1)
			ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans;
}

bool is_prime(ll x)
{
	if (x < 3)
		return x == 2;
	if (x % 2 == 0)
		return false;
	ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, d = x - 1, r = 0;
	while (d % 2 == 0)
		d /= 2, ++r;

	for (auto a : A)
	{
		ll v = qpow(a, d, x);
		if (v <= 1 || v == x - 1)
			continue; // a^d=0,说明a是x的倍数；a^d= 1 or -1

		for (int i = 0; i < r; i++)
		{
			v = v * v % x;
			if (v == x - 1 && i != r - 1)
			{
				v = 1;
				break;
			}
			if (v == 1)
				return false;
		}
		if (v != 1)
			return false;
	}
	return true;
}

int main()
{
	freopen("out.txt", "w", stdout);

	for (int i = 1; i < (int)1e8; i++)
	{
		if (is_prime(i))
			cout << i << '\n';
	}
	return 0;
}

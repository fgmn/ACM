#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 分治快速幂

ll qpow(ll x, ll y, ll mod) {
	ll res = 1;
	x %= mod;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

/*
ll qpow(ll x, ll y, ll mod)
{
	ll res = 1;
	for (x %= mod; y; y >>= 1, x = x * x % mod)
		if (y & 1)
			res = res * x % mod;
	return res;
}
*/

int main()
{
	return 0;
}

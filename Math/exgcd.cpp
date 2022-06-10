#include <bits/stdc++.h>
using namespace std;

// 递归，返回一组解

int exgcd(int a, int b, int &x, int &y)
{
	int r;
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		r = exgcd(b, a % b, x, y);
		int t = x;
		x = y;
		y = t - (a / b) * y;
	}
	return r;
	// r实际是gcd?
}

int main()
{
	int x, y;
	exgcd(17, 18, x, y);
	cout << x << ' ' << y;
	// 任意给定一组初值

	return 0;
}

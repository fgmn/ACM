#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
BIT: Binary indexed tree
单点更新，区间查询

维护区间为(1, n]，若要维护‘0’或者负数可以平移区间
*/

const int N = 1e6 + 10;
ll a[N];
int n, q; // 节点总数，询问数

int lowbit(int x) {
    return x & (-x);
}

// 单点更新
void update(int x, ll y)
{
    while (x <= n)  // 表示维护区间的上限，不一定等于n
    {
        a[x] += y;
        x += lowbit(x);
    }
}

// 区间查询
ll getsum(int x)
{
    ll res = 0;
    while (x > 0)
    {
        res += a[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    cin >> n >> q;

    for (int i = 1, j; i <= n; i++)
    {
        cin >> j;
        update(i, j);
    }

    int a, b;
    ll c;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
            update(b, c);   // a[b] += c 
        else
            cout << (getsum((int)c) - getsum(b - 1)) << endl;   // 查询[b, c]区间和
    }
    return 0;
}

/*
最大值维护，单点更新，区间维护


// 赋值操作： A[x] = y
void update(int x, int y) {
    h[x] = y;
    while (x <= N) {
        // 重新求解区间(x - lowbit(x), x]最大值
        for (int i = 1; i < lowbit(x); i <<= 1) {
            h[x] = max(h[x], h[x - i]);
        }
        x += lowbit(x);
    }
}

int query(int x, int y)
{
	int ans = 0;
	while (y >= x)
	{
		ans = max(A[y], ans);
		y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y))
			ans = max(h[y], ans);
	}
	return ans;
}
*/
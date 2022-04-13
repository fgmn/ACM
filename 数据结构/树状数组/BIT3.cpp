#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
ll a[N], s1[N], s2[N];
int n, q;

void update(int x, ll y)
{
    int cur = x;
    while (x <= n)
    {
        s1[x] += y;
        s2[x] += y * (cur - 1);
        x += x & (-x);
    }
}

ll getsum(int x)
{
    ll res = 0, cur = x;
    while (x > 0)
    {
        res += cur * s1[x] - s2[x];
        x -= x & (-x);
    }
    return res;
}

int main()
{
    cin >> n >> q;

    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }

    ll d;
    for (int i = 0, choi, c1, c2; i < q; i++)
    {
        cin >> choi;
        if (choi == 1)
        {
            cin >> c1 >> c2 >> d;
            update(c1, d);
            update(c2 + 1, -d);
        }
        else
        {
            cin >> c1 >> c2;
            cout << getsum(c2) - getsum(c1 - 1) << '\n';
        }
    }
    return 0;
}
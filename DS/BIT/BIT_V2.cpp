#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
ll a[N], s[N];
int n, q;

void update(int x, ll y)
{
    while (x <= n)
    {
        s[x] += y;
        x += x & (-x);
    }
}

ll get(int x)
{
    ll res = 0;
    while (x > 0)
    {
        res += s[x];
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
        update(i, a[i] - a[i - 1]); // 差分
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
            cin >> c1;
            cout << get(c1) << '\n';
        }
    }
    return 0;
}
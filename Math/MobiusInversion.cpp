#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int mu[N], cnt, prim[N], presum[N];
bool vis[N];

void get_mu(int n)
{
    mu[1] = 1, cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            mu[i] = -1;
            prim[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prim[j] <= n; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                mu[i * prim[j]] = 0;
                break;
            }
            else
                mu[i * prim[j]] = -mu[i];
        }
    }

    for (int i = 1; i <= n; i++)
        presum[i] = presum[i - 1] + mu[i];
}

int main()
{

    get_mu((int)5e4);

    int T;
    cin >> T;
    while (T--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        long long ans = 0;
        if (a > b)
            swap(a, b);

        for (int l = 1, r; l <= a; l = r + 1)
        {
            r = min(a / (a / l), b / (b / l));                                        // a/(l*d)： 可能除0错误
            ans += 1ll * (a / (l * d)) * (b / (l * d)) * (presum[r] - presum[l - 1]); // 溢出
        }
        cout << ans << '\n';
    }

    return 0;
}
#include<iostream>
using namespace std;
using ll = long long;

// 背包问题

const int N = 5005;
int w[N], c[N];     // 重量(体积)、价值
int f[N][N];        // f[i][j]：考虑前i个物品时占用空间为j的最大价值

// 01背包
void solve() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            if (j >= w[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + c[i]);
            else f[i][j] = f[i - 1][j];
        }
        // 滚动数组优化
        /*for (int j = v; j >= 0; j--) {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
        }*/
    }
    cout << f[n][v] << '\n';
}

// 完全背包
void solve1() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            for (int k = 0; k <= v / w[i]; k++) {
                if (j >= w[i] * k)
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i] * k] + c[i] * k);
                else break;
            }
        }
    }
    cout << f[n][v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// 多重背包
/*
const int N = 1e6 + 10;
int w[N], c[N], k[N];   // k:物品个数
int W[N], C[N];
ll f[N];

void solve() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> k[i];
    }

    // 二进制拆分->01背包
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = k[i];
        for (int j = 1; j <= t; j <<= 1) {
            cnt++;
            C[cnt] = j * c[i];
            W[cnt] = j * w[i];
            t -= j;
        }
        if (t > 0) {
            cnt++;
            C[cnt] = t * c[i];
            W[cnt] = t * w[i];
        }
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = v; j > 0; j--) {
            if (j >= W[i])
                f[j] = max(f[j], f[j - W[i]] + C[i]);
            else break;
        }
    }

    cout << f[v] << '\n';
}*/

// 分组背包
/*
const int N = 1005;
vector<pair<int, int> > s[105];
int f[N];

void solve() {
    int n, v;
    cin >> n >> v;

    int w, c, k;
    for (int i = 1; i <= n; i++) {
        cin >> w >> c >> k;     // k为组别
        s[k].push_back({w, c});
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = v; j > 0; j--) {
            for (auto k : s[i]) {
                if (j >= k.first)
                    f[j] = max(f[j], f[j - k.first] + k.second);
            }
        }
    }
    cout << f[v] << '\n';
}
*/
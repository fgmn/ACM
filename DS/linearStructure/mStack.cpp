#include<iostream>
#include<stack>
using namespace std;
using ll = long long;
const int N = 100010;

// 单调栈：求取数字 左右 相邻(第一个) 更小或者更大值

int a[N], L[N], R[N];   // L：记录左侧最近更小值 R：记录右侧更小值

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {  // 严格单调递增
            R[stk.top()] = i - 1;   // 找到此时栈顶的R
            stk.pop();
        }
        if (!stk.empty()) L[i] = stk.top() + 1;     // i找到L
        else L[i] = 0;  // 若此时栈空则i为当前最小
        stk.push(i);
    }

    while (!stk.empty()) {  // 剩余在栈中的数后面不存在小于它们的数，否则弹栈
        R[stk.top()] = n - 1;
        stk.pop();
    }

    ll ans  = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1ll * a[i] * (R[i] - L[i] + 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
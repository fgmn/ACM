#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

// 单调队列：求区间最值

deque<int> Q;
int a[1000010];
int n, k;

void find(int opt) {
    Q.clear();
    for (int i = 0; i < n; i++) {
        while (!Q.empty() && Q.front() < i - k + 1) Q.pop_front();
        while (!Q.empty() && a[Q.back()] >= a[i]) Q.pop_back();     // 保证队列严格递增
        Q.push_back(i);
        if (i >= k - 1) cout << opt * a[Q.front()] << " ";  // 读入k个数之后开始判断
    }
    cout << '\n';
}

void solve() {
    
    cin >> n >> k;  // 数字数目，区间长度

    for (int i = 0; i < n; i++) cin >> a[i];
    find(1);
    for (int i = 0; i < n; i++) a[i] = -a[i];   // 取反后，转化为求取最大值
    find(-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
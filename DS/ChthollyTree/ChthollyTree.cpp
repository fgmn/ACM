#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

// https://zhuanlan.zhihu.com/p/106353082

struct node {
    ll l, r;
    mutable ll v;   // 这里mutable要写不然可能会CE
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {}
    bool operator < (const node &a) const { return l < a.l; }
};

set<node> tree;

set<node>::iterator split(ll pos) {
    auto it = tree.lower_bound(node(pos, 0, 0));    // 寻找左端点第一个>=pos的节点
    if (it != tree.end() && it->l == pos)   // 如果已经存在以pos为左端点的节点，直接返回
        return it;
    it--;   // 否则断点在前一个节点中
    ll L = it->l, R = it->r, V = it->v;
    tree.erase(it);
    tree.insert(node(L, pos - 1, V));
    return tree.insert(node(pos, R, V)).first;  // 返回以pos为开头节点的迭代器
}

void assign(ll l, ll r, ll v) {
    auto end = split(r + 1), begin = split(l);  // 顺序不能颠倒
    tree.erase(begin, end);
    tree.insert(node(l, r, v));
}

void solve() {
    int n; cin >> n;
    tree.insert(node(1, n, 0));
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        assign(a, b, 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        auto end = split(b + 1), begin = split(a);
        for (auto j = begin; j != end; j++) {
            if (j->v == 1)  {
                ans += (j->r - j->l);
                // cout << j->l << ' ' << j->r << '\n';
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define lson l, mid, tree[rt].l
#define rson mid + 1, r, tree[rt].r
#define ls tree[rt].l
#define rs tree[rt].r

const int mac = 3e5 + 10;
const int inf = 1e9 + 10;

struct node
{
	int l, r, sum, f;
} tree[mac * 50];

int sz = 1; // 1为根节点

void pushdown(int l, int r, int rt)
{
	int mid = (l + r) >> 1;

	if (l != r)
	{
		if (!tree[rt].l)
			tree[rt].l = ++sz;
		if (!tree[rt].r)
			tree[rt].r = ++sz;
		if (tree[rt].f == 2)
			tree[rs].sum = tree[ls].sum = 0; // 子节点个数
		else
		{
			tree[ls].sum = mid - l + 1;
			tree[rs].sum = r - mid;
		}
		tree[ls].f = tree[rt].f;
		tree[rs].f = tree[rt].f; // 懒标记下放
	}
	tree[rt].f = 0;
}

void update(int l, int r, int &rt, int L, int R, int val)
{
	if (!rt)
		rt = ++sz; // 虚点->实点

	if (l >= L && r <= R)
	{
		if (val == 2)
			tree[rt].sum = 0;
		else
			tree[rt].sum = r - l + 1;

		tree[rt].f = val;

		return;
	}

	// 要用时建立节点
	if (tree[rt].f)
		pushdown(l, r, rt);

	int mid = (l + r) >> 1;

	if (mid >= L)
		update(lson, L, R, val);
	if (mid < R)
		update(rson, L, R, val);

	tree[rt].sum = tree[ls].sum + tree[rs].sum;
}

int main()
{

	// 超时
	// ios::sync_with_stdio(false);

	int n, q;

	scanf("%d%d", &n, &q);

	int root = 1;

	for (int i = 1; i <= q; i++)
	{
		int l, r, id;

		scanf("%d%d%d", &l, &r, &id);

		update(1, n, root, l, r, id);

		printf("%d\n", n - tree[1].sum);
	}

	return 0;
}

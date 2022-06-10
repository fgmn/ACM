#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int A[N];

// P1020 [NOIP1999 普及组] 导弹拦截
// （1）求最长单调不上升子序列长度 <-> 最长单调不下降子序列长度
// （2）Dilworth定理：偏序集的最少反链划分数等于最长链的长度 => 求最长上升子序列长度

int LIS(int a[], int n) {
	vector<int> stk(n + 1, 0);
	int top = 0;
	stk[++top] = a[0];
	
	for (int i = 1; i < n; i++) {
		if (stk[top] >= a[i]) {
			stk[++top] = a[i];
		}
		else {      // 末尾元素尽量小，替换比当前元素小的第一个元素
			int pos = upper_bound(stk.begin() + 1, stk.begin() + top + 1, a[i], greater<int>()) - stk.begin();
			stk[pos] = a[i];
		}
	}
	return top;
}

int LIS_(int a[], int n) {
	vector<int> stk(n + 1, 0);
	int top = 0;
	stk[++top] = a[0];
	
	for (int i = 1; i < n; i++) {
		if (stk[top] < a[i]) {
			stk[++top] = a[i];
		}
		else {	// stk[top] >= a[i]
			int pos = lower_bound(stk.begin() + 1, stk.begin() + top + 1, a[i]) - stk.begin();
			stk[pos] = a[i];
		}
	}
	return top;
}

int main() {
	
	string in;
	getline(cin, in);
	stringstream get(in);
	
	int i = 0;
	while (get >> A[i]) {
		i ++;
	}
	
	int ans1 = LIS(A, i), ans2 = LIS_(A, i);
	cout << ans1 << "\n" << ans2 << '\n';
	
	return 0;
}
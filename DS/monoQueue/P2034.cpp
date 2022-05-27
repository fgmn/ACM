#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Max = 1e5 + 10;

deque<int> Q;
ll dp[Max], A[Max];
//vector<ll> dp(Max), A(Max);
ll sum = 0;
// n:1e5 digit: 1e9 
// 单调队列优化 DP
 
int main(){
	int n, k;
	cin >> n >> k;
	
	for (int i=1; i<=n; i++) cin >> A[i], sum += A[i];
	
	for (int i=1; i<=n; i++) {	
		
		if(i <= k+1) dp[i] = A[i];
		else {
			dp[i] = A[i] + dp[Q.front()];
		}
		
		if(!Q.empty( ) && i - Q.front() >= k+1) Q.pop_front();
		while(!Q.empty() && dp[Q.back()] > dp[i]) Q.pop_back();
		Q.push_back(i);
	}
	
	cout << sum - dp[Q.front()] << '\n';
//	cout << *min_element(dp.end()-k-1, dp.end()) << '\n';
//	cout << sum - *min_element(dp.end()-k-1, dp.end()) << '\n';
	// 返回 迭代器 
	return 0;
}


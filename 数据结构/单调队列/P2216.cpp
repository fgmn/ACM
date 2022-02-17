#include<bits/stdc++.h>
using namespace std;

// a,b:1000 n:100
int Max[1005][1005], Min[1005][1005];
int Mx[1005][1005], Mn[1005][1005];
int A[1005][1005];
deque<int> Q1, Q2;		// 储存 num 

int main(){
	int a, b, n; cin >> a >> b >> n;
	
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> A[i][j];
		}
	} 
	
	for (int i = 1; i <= a; i++) {
		Q1.clear();Q2.clear();
		for (int j = 1; j <= b; j++) {
			if (!Q1.empty() && j - Q1.front() >= n) Q1.pop_front();
			while (!Q1.empty() && A[i][Q1.back()] < A[i][j]) 
				Q1.pop_back();
			Q1.push_back(j);
			if(j >= n) {
				Mx[i][j - n + 1] = A[i][Q1.front()];
			}
			// Min
			if (!Q2.empty() && j - Q2.front() >= n) Q2.pop_front();
			while (!Q2.empty() && A[i][Q2.back()] > A[i][j]) 
				Q2.pop_back();
			Q2.push_back(j);
			if(j >= n) {
				Mn[i][j - n + 1] = A[i][Q2.front()];
			}			
		}
	} 
	
	// 将新矩阵的每一列作为新序列， 再求一次区间最值 
	for (int i = 1; i <= (b - n + 1); i++) {
		Q1.clear();Q2.clear();
		for (int j = 1; j <= a; j++) {
			if (!Q1.empty() && j - Q1.front() >= n) Q1.pop_front();
			while (!Q1.empty() && Mx[Q1.back()][i] < Mx[j][i]) 
				Q1.pop_back();
			Q1.push_back(j);
			if(j >= n) {
				Max[j - n + 1][i] = Mx[Q1.front()][i];
			}
			// Min		
			if (!Q2.empty() && j - Q2.front() >= n) Q2.pop_front();
			while (!Q2.empty() && Mn[Q2.back()][i] > Mn[j][i]) 
				Q2.pop_back();
			Q2.push_back(j);
			if(j >= n) {
				Min[j - n + 1][i] = Mn[Q2.front()][i];
			}		
		}
	}
	
//	cout << '\n';
//	for (int i = 1; i <= a; i++) {
//		for (int j = 1; j <= b - n + 1; j++) {
//			cout << Mx[i][j] <<' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
	int ans = 2e9;
	for (int i = 1; i <= a - n + 1; i++) {
		for (int j = 1; j <= b - n + 1; j++) {
			ans = min (ans, Max[i][j] - Min[i][j]);
		}
//		cout << '\n';
	}
	cout << ans << '\n';
	
	return 0;
}


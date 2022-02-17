#include <bits/stdc++.h>
using namespace std;

int Mod;
 
struct mat{
	int n;
	vector<vector<long long> > val;
	
	//构造函数 
	explicit mat(int sz) : val(sz,vector<long long>(sz)){
		n = sz;
	}
	
	//单位矩阵 
	void emat(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				val[i][j] = (i==j);
			}
		}
	}
	
	//重载乘号
	mat operator * (const mat &a) const {
		mat res(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					res.val[i][j] = (res.val[i][j] + val[i][k] * a.val[k][j]) % Mod;
				}
			}
		}
		return res;
	} 
}; 

//快速幂
mat matqp(mat &a, long long b) {
	mat res(a.n);
	res.emat();
	while(b){
		if(b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() { 
	// 计算Fibonacci的项 
	int cas;
	cin >> cas;
	
	while(cas--){
		long long n;
		cin >> n;
		cin >> Mod;		
		mat trans(2);
		
		trans.val[0][0]=0;
		trans.val[0][1]=1;
		trans.val[1][0]=1;
		trans.val[1][1]=1;
		
		mat res = matqp(trans,n);
		cout << res.val[0][1] << endl;	
	}
	
	return 0;
}


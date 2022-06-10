#include<iostream>
#include<vector>
using namespace std;

int Mod;

struct mat
{
	int n;
	vector<vector<long long>> x;

	// 构造函数
	explicit mat(int sz) : x(sz, vector<long long>(sz)) { n = sz; }

	// 单位矩阵
	void emat()
	{
		for (int i = 0; i < n; i++) {
			x[i][i] = 1;
		}
	}	// 重载运算之后单位矩阵的定义可能变化

	// 重载乘号
	mat operator*(const mat &a) const
	{
		mat res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res.x[i][j] = (res.x[i][j] + x[i][k] * a.x[k][j]) % Mod;
				}
			}
		}
		return res;
	}
};

// 矩阵快速幂
mat matqp(mat a, long long b)
{
	mat res(a.n);
	res.emat();
	while (b)
	{
		if (b & 1) res = res * a;	// 重载*乘法
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main()
{
	// 计算Fibonacci的项
	int cas;
	cin >> cas;

	while (cas--)
	{
		long long n;
		cin >> n;
		cin >> Mod;

		// 初始状态为[1,0]^T
		// f-1=1,f0=0
		mat t(2);
		t.x[0][0] = 0; t.x[0][1] = 1;
		t.x[1][0] = 1; t.x[1][1] = 1;

		mat res = matqp(t, n);
		cout << res.x[0][1] << endl;
	}

	return 0;
}

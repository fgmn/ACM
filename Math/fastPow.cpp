#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//分治快速幂 
ll ppow(ll x, ll y, ll mod) {
	ll res = 1;
	for(x %= mod; y; y >>= 1, x = x * x % mod)
		if (y & 1) res = res * x % mod;
	return res;
}

//ll ppow(ll x,ll y,ll mod){
//	ll res=1;
//	for(x%=mod;y;y--) res=res*x%mod;
//	return res;
//}

int main() {
	ll x=1070057505,y=1700078548;	//1e10
//	cin>>x>>y;
	ll ans=ppow(x,y,16);
	cout<<ans<<endl;
	 
	return 0;
}

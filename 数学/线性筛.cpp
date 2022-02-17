#include <bits/stdc++.h>
using namespace std;


//埃氏筛的时间复杂度为O(nloglogn)，线性筛的时间复杂度为O(n)
//后者的速度是前者的3-4倍，但在小数据中线性筛可能被完爆 

const long long maxn=1e8;

bool is_prime[maxn];
int prime[maxn];
int cnt;

void sieve(int n){
	memset(is_prime,1,sizeof(is_prime));
	is_prime[1]=0;
	for(int i=2;i<=n;i++){
		if(is_prime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			is_prime[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	freopen("outt.txt", "w", stdout);
	
	int n;
//	cin>>n;
	n = 1e6;
	sieve(n);
	for(int i=1;i<=cnt;i++){
		cout<<prime[i]<<'\n';
//		if(i%10==0) cout<<endl;
	}
	return 0;
}

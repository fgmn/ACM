#include <bits/stdc++.h>
using namespace std;

//时空上均优于线段树 

typedef long long ll;
const int maxn=1000010;
ll a[maxn];							//原始数组
int n,q;
ll s1[maxn],s2[maxn]; 				//差分树状数组 	//管辖区域为（pos-lowbit(pos),pos]

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){			//区域更新
	int cur=x; 
	while(x<=n){
		s1[x]+=y;					//同时维护两个数组的前缀和 
		s2[x]+=y*(cur-1);
		x+=lowbit(x);
	}
}

ll getsum(int x){					//区域查询
	ll res=0,cur=x;					//记录x的初始值 
	while(x>0){
		res+=cur*s1[x]-s2[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	//关掉流同步
//	std::ios::sync_with_stdio(false);
	 
	cin>>n>>q;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]-a[i-1]);		//差分
	} 
	
	for(int i=0;i<q;i++){
		int a; 
		cin>>a;
		
		if(a==1){
			int b,c;
			ll d;
			cin>>b>>c>>d;
			update(b,d);
		 	update(c+1,-d);
		} 
		else{
			int e,f;
			cin>>e>>f;
		 	cout<<getsum(f)-getsum(e-1)<<endl;		//得到前缀和数组 
		}
	}
	
	return 0;
}



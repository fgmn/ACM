#include <bits/stdc++.h>
using namespace std;

//通过差分转化为单点更新区域查询 

typedef long long ll;
const int maxn=1000010;
ll a[maxn];						//原始数组
int n,q;
ll s[maxn]; 					//差分树状数组 		//管辖区域为（pos-lowbit(pos),pos]

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){		//区域更新
	while(x<=n){
		s[x]+=y;
		x+=lowbit(x);
	}
}

ll get(int x){					//单点查询
	ll res=0;
	while(x>0){
		res+=s[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	
	cin>>n>>q;
	a[0]=0; 					//差分要对0初始化 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]-a[i-1]);	//差分		//实际上树状数组中维护的是差分数组
	} 
	
	for(int i=0;i<q;i++){
		int a; 
		cin>>a;
		
		if(a==1){    			//更新 
			int b,c;
			ll d;
			cin>>b>>c>>d;
			//将区域[b,c]加上d  
			update(b,d);
		 	update(c+1,-d);
		} 
		else{					//查询 
			int e;
			cin>>e;
		 	cout<<get(e)<<endl;	//按原思路求得差分数组的前缀和应该为原数组该点的值，实现单点查询 
		}
	}
	
	return 0;
}



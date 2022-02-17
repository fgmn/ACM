#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
//# define %p ' '
//可尝试根据平台参数预处理 

ll a[maxn],tree[maxn<<2],tag1[maxn<<2],tag2[maxn<<2];//tag1为乘法的懒标记，tag2为加 
int n,m,p;

void check(){
	for(int i=1;i<=4*n;i++) cout<<tree[i]<<' ';	
	cout<<'\n';
}

//建树 
//d[now]维护原数组下标[l,r] 
void build(int now,int l,int r){
	if(l==r){
		tree[now]=a[l]%p;
		return;
	}
	
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	tree[now]=(tree[now*2]+tree[now*2+1])%p;
}

//懒标记优化 
void pd(int now,int l,int r){
	int ls=now*2;
	int rs=now*2+1;
	
	int mid=(l+r)>>1;
	
	//懒标记下放 
	tag1[ls]=tag1[ls]*tag1[now]%p;
	tag2[ls]=(tag2[ls]*tag1[now]+tag2[now])%p;
	tag1[rs]=tag1[rs]*tag1[now]%p;
	tag2[rs]=(tag2[rs]*tag1[now]+tag2[now])%p;
	
	tree[ls]=(tag2[now]*(mid-l+1)+tree[ls]*tag1[now]%p)%p;
	tree[rs]=(tag2[now]*(r-mid)+tree[rs]*tag1[now]%p)%p;
	
	tag1[now]=1,tag2[now]=0;
	 
} 

//区间查询
//至多拆分成O(log n)个极大区间 
ll query(int now,int l,int r,int ql,int qr){
	ll sum=0;
	//完整地包含在询问区间中的极大区间,若不则还要拆分 
	if(ql<=l && qr>=r){
		sum=(sum+tree[now])%p;
		return sum;
	}
	
	pd(now,l,r);
			
	int mid=(l+r)>>1;
	if(ql<=mid) sum=(sum+query(now*2,l,mid,ql,qr))%p;
	if(qr>=mid+1) sum=(sum+query(now*2+1,mid+1,r,ql,qr))%p;
	return sum;
	 
}

//区间加 
void update2(int now,int l,int r,int xl,int xr,int c){
	if(xl<=l && xr>=r){
		tree[now]=(tree[now]+(r-l+1)*c)%p;
		tag2[now]=(tag2[now]+c)%p; 
		return;
	} 
	
	pd(now,l,r);
	
	int mid=(l+r)>>1;
	if(xl<=mid) update2(now*2,l,mid,xl,xr,c);
	if(xr>=mid+1) update2(now*2+1,mid+1,r,xl,xr,c);
	
	tree[now]=(tree[now*2]+tree[now*2+1])%p;
}

//区间乘 
void update1(int now,int l,int r,int xl,int xr,int c){
	if(xl<=l && xr>=r){
		tree[now]=tree[now]*c%p;
		tag1[now]=tag1[now]*c%p;
		tag2[now]=tag2[now]*c%p;
		
		return;
	} 
	
	pd(now,l,r);
	
	int mid=(l+r)>>1;
	if(xl<=mid) update1(now*2,l,mid,xl,xr,c);
	if(xr>=mid+1) update1(now*2+1,mid+1,r,xl,xr,c);
	
	tree[now]=(tree[now*2]+tree[now*2+1])%p;
}

//洛谷P3373 
int main() {
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>p;
	memset(tag2,0,sizeof tag2); //memset()只能整体赋值0和-1 
	for(int i=1;i<=4*n;i++) tag1[i]=1;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	build(1,1,n);
//	check(); 
	
	while(m--){
		int st;
		cin>>st;
		
		if(st==1){
			int x,y,k;
			cin>>x>>y>>k;
			update1(1,1,n,x,y,k);
//			check(); 
		}
		else if(st==2){
			int x,y,k;
			cin>>x>>y>>k;
			update2(1,1,n,x,y,k);
//			check();
		}
		else{
			int x,y;
			cin>>x>>y;
			ll ans=query(1,1,n,x,y)%p;
			cout<<ans<<endl;
//			check();
			
		} 
	} 
	return 0;
}














#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

int a[maxn],tree[maxn<<2],tag[maxn<<2];
int n;

void check(){
	for(int i=1;i<=4*n;i++) cout<<tree[i]<<' ';
	cout<<'\n';
}


//���� 
//d[now]ά��ԭ�����±�[l,r] 
void build(int now,int l,int r){
	if(l==r){
		tree[now]=a[l];
		return;
	}
	
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	tree[now]=tree[now*2]+tree[now*2+1];
}

//������Ż� 
void pd(int now,int l,int r){
	int ls=now*2;
	int lr=now*2+1;
	
	int mid=(l+r)>>1;
	tag[ls]+=tag[now];
	tag[lr]+=tag[now];
	
	tree[ls]+=tag[now]*(mid-l+1);
	tree[lr]+=tag[now]*(r-mid);
	
	tag[now]=0;
	 
} 

//�����ѯ
//�����ֳ�O(log n)���������� 
ll query(int now,int l,int r,int ql,int qr){
	ll sum=0;
	//�����ذ�����ѯ�������еļ�������,������Ҫ��� 
	if(ql<=l && qr>=r){
		sum+=tree[now];
		return sum;
	}
	
	pd(now,l,r);
			
	int mid=(l+r)>>1;
	if(ql<=mid) sum+=query(now*2,l,mid,ql,qr);
	if(qr>=mid+1) sum+=query(now*2+1,mid+1,r,ql,qr);
	return sum;
	 
}

//�����޸�
//�ݹ��ҵ�Ҫ�޸ĵ�xλ�� 
void update(int now,int l,int r,int x,int uy){
	if(l==r){
		tree[now]+=uy;
		return;
	} 
	
	int mid=(l+r)>>1;
	if(x<=mid) update(now*2,l,mid,x,uy);
	else update(now*2+1,mid+1,r,x,uy);
	
	tree[now]=tree[now*2]+tree[now*2+1];
	
}

//�����޸�(�ӷ�) 
void updatee(int now,int l,int r,int xl,int xr,int c){
	if(xl<=l && xr>=r){
		tree[now]+=(r-l+1)*c;
		tag[now]+=c;
		return;
	} 
	
	pd(now,l,r);
	
	int mid=(l+r)>>1;
	if(xl<=mid) updatee(now*2,l,mid,xl,xr,c);
	if(xr>=mid+1) updatee(now*2+1,mid+1,r,xl,xr,c);
	
	tree[now]=tree[now*2]+tree[now*2+1];
}
 

int main(){
	n=5;
	a[1]=1;
	a[2]=5;
	a[3]=4;
	a[4]=2;
	a[5]=3;
	build(1,1,n);
	check();
	updatee(1,1,n,1,4,1);
	check();
	cout<<query(1,1,n,2,5)<<endl;
	check();
	return 0;
} 





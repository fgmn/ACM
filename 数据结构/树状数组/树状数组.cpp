#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=1000010;			//树状数组的大小 

ll a[maxn];						//树状数组			//管辖区域为（pos-lowbit(pos),pos]
//ll t[maxn];						//维护区间最大值 
//节点数为int型，每个节点数据范围为long long型 
int n,q;

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){		//单点更新
	while(x<=n){
		a[x]+=y;				//ll+int 
		x+=lowbit(x);
	}
}

ll getsum(int x){ 				//区间查询
	ll res=0;
	while(x>0){
		res+=a[x];
		x-=lowbit(x);
	}
	return res;
}

int main() {
	
	cin>>n>>q;					//输入节点数及更新询问数 
	
	//初始化 
	for(int i=1;i<=n;i++){		//维护区间[1,n] //注意0节点 
		//cin>>a[i];
		int j;
		cin>>j;
		update(i,j); 
	} 
	
	for(int i=0;i<q;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		
		if(a==1) update(b,c);									//更新 
		else cout<<(getsum((int)c)-getsum(b-1))<<endl;			//区域查询：求取区域和；实际是得到前缀和相减 
	}
	
	return 0;
}

//维护区间最大值 

//void Update(int i,ll v)
//{
//    while(i<=n)
//    {
//        t[i] = max(t[i],v);
//        i += lowbit(i);
//    }
//}
//int query(int i)
//{
//    int ans = 0;
//    while(i)
//    {
//        ans = max(ans,t[i]);
//        i -= lowbit(i);
//    }
//    return ans;
//}

//求逆序对
//先将a[]离散化为b[] 
/*
void update(int p)
{
    while(p<=n)
    {
        a[p] ++;
        p+=lowbit(p);
    }
}
 
int getsum(int p)
{
    int res = 0;
    while(p)
        res += a[p],p -= lowbit(p);
    return res;
}

for(int i=1;i<=n;i++){
    update(b[i]+1);
    res += i-getsum(b[i]+1);
}

*/ 



















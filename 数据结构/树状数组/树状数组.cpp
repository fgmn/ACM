#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=1000010;			//��״����Ĵ�С 

ll a[maxn];						//��״����			//��Ͻ����Ϊ��pos-lowbit(pos),pos]
//ll t[maxn];						//ά���������ֵ 
//�ڵ���Ϊint�ͣ�ÿ���ڵ����ݷ�ΧΪlong long�� 
int n,q;

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){		//�������
	while(x<=n){
		a[x]+=y;				//ll+int 
		x+=lowbit(x);
	}
}

ll getsum(int x){ 				//�����ѯ
	ll res=0;
	while(x>0){
		res+=a[x];
		x-=lowbit(x);
	}
	return res;
}

int main() {
	
	cin>>n>>q;					//����ڵ���������ѯ���� 
	
	//��ʼ�� 
	for(int i=1;i<=n;i++){		//ά������[1,n] //ע��0�ڵ� 
		//cin>>a[i];
		int j;
		cin>>j;
		update(i,j); 
	} 
	
	for(int i=0;i<q;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		
		if(a==1) update(b,c);									//���� 
		else cout<<(getsum((int)c)-getsum(b-1))<<endl;			//�����ѯ����ȡ����ͣ�ʵ���ǵõ�ǰ׺����� 
	}
	
	return 0;
}

//ά���������ֵ 

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

//�������
//�Ƚ�a[]��ɢ��Ϊb[] 
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



















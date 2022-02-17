#include <bits/stdc++.h>
using namespace std;

//ʱ���Ͼ������߶��� 

typedef long long ll;
const int maxn=1000010;
ll a[maxn];							//ԭʼ����
int n,q;
ll s1[maxn],s2[maxn]; 				//�����״���� 	//��Ͻ����Ϊ��pos-lowbit(pos),pos]

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){			//�������
	int cur=x; 
	while(x<=n){
		s1[x]+=y;					//ͬʱά�����������ǰ׺�� 
		s2[x]+=y*(cur-1);
		x+=lowbit(x);
	}
}

ll getsum(int x){					//�����ѯ
	ll res=0,cur=x;					//��¼x�ĳ�ʼֵ 
	while(x>0){
		res+=cur*s1[x]-s2[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	//�ص���ͬ��
//	std::ios::sync_with_stdio(false);
	 
	cin>>n>>q;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]-a[i-1]);		//���
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
		 	cout<<getsum(f)-getsum(e-1)<<endl;		//�õ�ǰ׺������ 
		}
	}
	
	return 0;
}



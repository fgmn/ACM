#include <bits/stdc++.h>
using namespace std;

//ͨ�����ת��Ϊ������������ѯ 

typedef long long ll;
const int maxn=1000010;
ll a[maxn];						//ԭʼ����
int n,q;
ll s[maxn]; 					//�����״���� 		//��Ͻ����Ϊ��pos-lowbit(pos),pos]

int lowbit(int x){
	return x&(-x);
}

void update(int x,ll y){		//�������
	while(x<=n){
		s[x]+=y;
		x+=lowbit(x);
	}
}

ll get(int x){					//�����ѯ
	ll res=0;
	while(x>0){
		res+=s[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	
	cin>>n>>q;
	a[0]=0; 					//���Ҫ��0��ʼ�� 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]-a[i-1]);	//���		//ʵ������״������ά�����ǲ������
	} 
	
	for(int i=0;i<q;i++){
		int a; 
		cin>>a;
		
		if(a==1){    			//���� 
			int b,c;
			ll d;
			cin>>b>>c>>d;
			//������[b,c]����d  
			update(b,d);
		 	update(c+1,-d);
		} 
		else{					//��ѯ 
			int e;
			cin>>e;
		 	cout<<get(e)<<endl;	//��ԭ˼·��ò�������ǰ׺��Ӧ��Ϊԭ����õ��ֵ��ʵ�ֵ����ѯ 
		}
	}
	
	return 0;
}



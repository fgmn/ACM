#include <bits/stdc++.h>
using namespace std;
const int maxn=3e4+10;

int v[maxn],f[maxn],s[maxn];

void ini(){
	for(int i=1;i<=maxn;i++) f[i]=i;
	for(int i=1;i<maxn;i++) s[i]=1;
}

int find(int x){
	if(x==f[x]) return x;
	else{
		int t=f[x];
		f[x]=find(f[x]);
		v[x]+=v[t];		//���ڵ��Ϊ���ڵ㣬�����ڵ�ľ���Ϊԭ�ȸ��ڵ㵽���ľ�����ϵ�ǰ�ڵ㵽���ľ��� 
		return f[x];
	}
} 

void merge(int x,int y){
	int f1=find(x),f2=find(y);
	if(f1!=f2){
		f[f1]=f2;
		v[f1]=s[f2];	//ά����s[]��ʾ��ǰ��ͨ��Ĵ�С 
		s[f2]+=s[f1];	
	} 
} 

int main() {
	int cas;
	cin>>cas;
	
	ini();
	
	while(cas--){
		char m;
		int i,j;
		
		cin>>m>>i>>j;
		
		if(m=='M'){
			merge(i,j);
		}
		else{
			if(find(i)!=find(j)) cout<<-1<<endl;
			else cout<<abs(v[i]-v[j])-1<<endl;
			
		}
	} 
	return 0;
}

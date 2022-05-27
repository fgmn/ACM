#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int f[maxn];

void ini() {
	for(int i=1;i<maxn;i++) f[i]=i;
}
int find(int x){
	if(x==f[x]) return x;//若是根节点直接返回 
	return f[x]=find(f[x]);
} 

void merge(int x,int y){
	int f1=find(x),f2=find(y);
	if(f1!=f2) f[f1]=f2;
} 

int main() {
	ini();
	int n,m;
	cin>>n>>m;
	while(m--){
		int z,x,y;
		cin>>z>>x>>y;
		
		if(z==1) merge(x,y);
		else{
			if(find(x)!=find(y)) cout<<'N'<<endl;
			else cout<<'Y'<<endl;
		}
	}
	return 0;
}

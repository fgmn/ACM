#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 1e5+10;
int n; 
int point[N],v[N],nxt[N],len[N],can[N],cnt[N];
//can[]Ϊ����״̬��ǣ�cnt[]�浽�ýڵ����·�ı��� 
int dis[N];		//���·����
 
void spfa(int s){
	for(int i=1;i<=n;i++) can[i]=0,dis[i]=inf,cnt[i]=0;
	dis[s]=0;can[s]=1;
	queue<int> p;
	p.push(s);
	
	while(!p.empty()){
		int now=p.front();p.pop();
		for(int i=point[now];i;i=nxt[i]){ 		//��ʽǰ����:Ϊ�߱�ţ�v[]������������ܵ���ĵ� 
			if(dis[v[i]] > dis[now]+len[i]){
				dis[v[i]] = dis[now]+len[i];
//				pre[v[i]] = now;
				cnt[v[i]]=cnt[now]+1;
				 
				if(cnt[v[i]] >= n){
					//���ڸ��� 
				}
				if(!can[v[i]]){		//can[]��¼�ڵ��Ƿ��ڶ�����,��ֹ�ظ���� 
					can[v[i]]=1;
					p.push(v[i]);
				}
			}
		can[now]=0;
		} 
	}
} 

int main() {
	
	return 0;
}

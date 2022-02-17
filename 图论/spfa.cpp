#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 1e5+10;
int n; 
int point[N],v[N],nxt[N],len[N],can[N],cnt[N];
//can[]为访问状态标记，cnt[]存到该节点最短路的边数 
int dis[N];		//最短路距离
 
void spfa(int s){
	for(int i=1;i<=n;i++) can[i]=0,dis[i]=inf,cnt[i]=0;
	dis[s]=0;can[s]=1;
	queue<int> p;
	p.push(s);
	
	while(!p.empty()){
		int now=p.front();p.pop();
		for(int i=point[now];i;i=nxt[i]){ 		//链式前项星:为边编号，v[]存的是这条边能到达的点 
			if(dis[v[i]] > dis[now]+len[i]){
				dis[v[i]] = dis[now]+len[i];
//				pre[v[i]] = now;
				cnt[v[i]]=cnt[now]+1;
				 
				if(cnt[v[i]] >= n){
					//存在负环 
				}
				if(!can[v[i]]){		//can[]记录节点是否在队列中,防止重复入队 
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

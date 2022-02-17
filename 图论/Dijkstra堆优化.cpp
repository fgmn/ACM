#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

//��ʹ��pair���
struct node {
    int end;		//�յ�
    int power;		//Ȩֵ��������Ȩͼ��Ϊ 1 
} t;

const int maxn = 100010;

int n;					 //nΪ����
vector<node> q[maxn];	 //�ڽӱ� 
int dis[maxn];			 //��̾������� 
int vis[maxn];			 //�������

priority_queue<pair<int,int> > pq;

void Dijkstra(int start) {
    memset(dis, INF, sizeof dis);
    dis[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        
        if(vis[x]) continue;
        vis[x] = 1;
        
 		//����dis����
		int len = q[x].size();			
        for(int j = 0; j < len; j++) {
            if(vis[q[x][j].end] == 0 && dis[q[x][j].end] > q[x][j].power + dis[x]) {
                dis[q[x][j].end] = q[x][j].power + dis[x];
                qu.push({-dis[q[x][j].end], q[x][j].end});
            }
        }
    }
}


int main()
{
    int m,i;
    int begin,end,power;
    int a,b;
    scanf("%d%d%d",&n,&m,&a);

	for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&begin,&end,&power);
        t.end=end;
        t.power=power;
        q[begin].push_back(t);
    }

	Dijkstra(a); 
	
	for(int t=0;t<n;++t){
		if(dis[t]==INF){
			printf("INF\n");
		}
		else{
			printf("%d\n",dis[t]);
		}
	} 
	
    return 0;
}






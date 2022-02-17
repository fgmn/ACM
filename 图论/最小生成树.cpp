#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=100010;

int n,m;
long long sum;		

struct node
{
    int start;		//���
    int end;		//�յ�
    int power;		//Ȩֵ
} edge[maxn];

int pre[maxn];		//����������� 

//�ȽϺ�����1����������� 2��cmp���� 
bool cmp(node a,node b)
{
    return a.power<b.power;
}

int Find(int x)
{
    if(x!=pre[x])
    {
        pre[x]=Find(pre[x]);
    }
    return pre[x];

}

void Union(int x,int y,int n)
{
    int fx =Find(x);
    int fy =Find(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
        sum+=edge[n].power;
    }
}

int main()
{
    int i;

    sum=0;
    cin>>n>>m;
	    
    for(i=1;i<=m;i++) scanf("%d%d%d",&edge[i].start,&edge[i].end,&edge[i].power);
        
    for(i=1;i<=m;i++) pre[i]=i;
        
    //�Ա߰�Ȩֵ��     
    sort(edge+1,edge+m+1,cmp);
        
    for(i=1;i<=m;i++) Union(edge[i].start,edge[i].end,i);
        
    printf("%lld\n",sum);
    
    return 0;
}






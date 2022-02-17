#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
ll a[N]; 
int n,q;        //节点总数，询问数

//单点更新
void update(int x, ll y){
    while(x <= n){
        a[x] += y;
        x += x&(-x);
    }
}

//区间查询
ll getsum(int x){
    ll res = 0;
    while(x > 0){
        res += a[x];
        x -= x&(-x);
    }
    return res;
}

int main(){
    cin >> n >> q;

    for(int i=1,j;i<=n;i++){
        cin >> j;
        update(i, j);
    }

    int a,b; ll c;
    for(int i=0;i<q;i++){
        cin >> a >> b >> c;
        
        if(a == 1) update(b, c);
        else cout << (getsum((int)c)-getsum(b-1)) << endl; 
    }
    return 0;
}
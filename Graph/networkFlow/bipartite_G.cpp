#include<bits/stdc++.h>
using namespace std;

/*
匈牙利算法 
n 与 n 个节点进行匹配，有 m 条边
邻接矩阵算法时间复杂度：O(n^3)
邻接表：O(nm)
*/ 


const int N = 605;
int n, m, e, use[N];
bool eg[N][N], vis[N];	// vis 保证増广路节点不重复 


bool search(int now) {
    for(int i = 1; i <= m; i++) {
        if (eg[now][i] && !vis[i]) {
            vis[i] = 1;
            if (!use[i] || search(use[i])) {
                use[i] = now;
                return 1;
            }
        }
    }
    return 0;
}

int get() {
    cin >> n >> m >> e;
    for (int i = 1, u, v; i <= e; i++) {
        cin >> u >> v;
        eg[u][v] = 1;
    }
   	
	// 最大匹配数
    int ans = 0;
    
    // 为 n 个点寻找匹配 
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        ans += search(i);
    }
    
    cout << ans << '\n';
    return 0;
}

int main() {
    return get() && 0;
}

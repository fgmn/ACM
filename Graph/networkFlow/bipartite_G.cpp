#include<bits/stdc++.h>
using namespace std;

/*
�������㷨 
n �� n ���ڵ����ƥ�䣬�� m ����
�ڽӾ����㷨ʱ�临�Ӷȣ�O(n^3)
�ڽӱ�O(nm)
*/ 


const int N = 605;
int n, m, e, use[N];
bool eg[N][N], vis[N];	// vis ��֤����·�ڵ㲻�ظ� 


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
   	
	// ���ƥ����
    int ans = 0;
    
    // Ϊ n ����Ѱ��ƥ�� 
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

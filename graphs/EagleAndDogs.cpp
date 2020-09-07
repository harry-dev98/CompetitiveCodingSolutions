#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G(100001, vector<int>(100001));

int DFS(int cv, bool vis[], int n){
    vis[cv] = 1;
    int local_max = 0;
    for(int i=1; i<=n; i++){
        if(vis[i] == 0 && G[cv][i] != 0){
            local_max = max(DFS(i, vis, n) + G[cv][i], local_max);
        }
    }
    return local_max;
}


int main(){
    int n, t, v, u, d;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                G[i][j] = 0;
            }
        }
        for(int i=0; i<n-1; i++){
            cin>>v>>u>>d;
            G[v][u] = d;
            G[u][v] = d;
        }
        int xx = 1000000001;
        for(int i=1; i<=n; i++){
            bool vis[n+1];
            memset(vis, 0, sizeof(vis));
            cout<<DFS(i, vis, n)<<" ";
        }
        cout<<"\n";
    }
}
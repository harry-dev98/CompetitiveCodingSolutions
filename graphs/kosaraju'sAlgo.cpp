#include<bits/stdc++.h>
using namespace std;

void dfs(int cv, vector<int> adj[], bool vis[], stack<int> &S){
    vis[cv] = 1;
    for(auto edge:adj[cv]){
        if(vis[edge] == 0){
            dfs(edge, adj, vis, S);
        }
    }
    S.push(cv);
}

void vanilla_dfs(int cv, vector<int> adj[], bool vis[]){
    vis[cv] = 1;
    for(auto edge:adj[cv]){
        if(vis[edge] == 0){
            vanilla_dfs(edge, adj, vis);
        }
    }
}


int kosaraju_SCC(int v, vector<int> adj[]){
    stack<int> S;
    bool vis[v];
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<v; i++){
        if(vis[i] == 0){
            dfs(i, adj, vis, S);
        }
    }
    vector<int>adj_[v];
    for(int i=0; i<v; i++){
        for(auto edg:adj[i]){
            adj_[edg].push_back(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    while(!S.empty()){
        int cv = S.top();
        if(vis[cv] == 0){
            vanilla_dfs(cv, adj_, vis);
            ans++;
        }
        S.pop();
    }
    return ans;
}


int main(){
    int v, e, x, y;
    cin>>v>>e;
    vector<int> Adj[v];//, Adj_[v];
    for(int i=0; i<3; i++){
        cin>>x>>y;
        Adj[x].push_back(y);
        // Adj_[y].push_back(x);
    }
    cout<<kosaraju_SCC(v, Adj)<<"\n";
    return 0;
}
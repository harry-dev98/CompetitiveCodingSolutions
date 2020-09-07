#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define pii pair<int,int>

int bfs(int cv, int& farV, vector<int> Adj[], int n){
    queue<pii> Q;
    vector<bool>vis(n, 0);
    Q.push({cv, 0});
    vis[cv] = 1;
    int d = 0;
    farV = cv;
    pii top;
    while(!Q.empty()){
        top = Q.front();Q.pop();
        cv = top.first;
        for(auto v:Adj[cv]){
            if(!vis[v]){
                Q.push({v, top.second+1});
                vis[v] = 1;
            }  
        }
        if(top.second > d){
            d = top.second;
            farV = top.first;
        }
    }
    return d;
}

void dfs(int cv, vector<int> Adj[], int k, vector<int>& ans, vector<bool>& vis){
    if(k == 0){
        if(!vis[cv]){
            ans[cv]++;
            vis[cv] = 1;
        }
        return;
    }
    for(auto v: Adj[cv]){
        dfs(v, Adj, k-1, ans, vis);
    }
}

int main(){
    int n, a, b;
    cin>>n;
    vector<int> Adj[n];
    if(n == 1){
        cout<<1<<'\n';
    }
    else{
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--;b--;
            Adj[a].push_back(b);
            Adj[b].push_back(a);
        }
        int farAwayV1, farAwayV2;
        int dis = bfs(0, farAwayV1, Adj, n);
        dis = bfs(farAwayV1, farAwayV2, Adj, n);
        vector<int> ans(n, dis);
        vector<bool> vis(n, 0);
        dfs(farAwayV1, Adj, dis, ans, vis);
        dfs(farAwayV2, Adj, dis, ans, vis);
        for(auto a: ans){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
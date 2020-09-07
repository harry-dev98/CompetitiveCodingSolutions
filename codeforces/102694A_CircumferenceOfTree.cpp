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

int main(){
    int n, a, b;
    cin>>n;
    vector<int> Adj[n];
    if(n == 1){
        cout<<0<<'\n';
    }
    else{
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--;b--;
            Adj[a].push_back(b);
            Adj[b].push_back(a);
        }
        int farAwayV;
        int dis = bfs(0, farAwayV, Adj, n);
        dis = bfs(farAwayV, farAwayV, Adj, n);
        cout<<3 * dis<<"\n";
    }
    return 0;
}
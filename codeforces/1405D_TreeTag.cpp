#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> G[N];

bool dfs(int cv, int dest, int depth, int p=-1){
    if(depth<0)return 0;
    if(cv == dest){
        return 1;
    }
    bool ans = 0;
    for(auto v:G[cv]){
        if(v!=p){
            ans |= dfs(v, dest, depth-1, cv);
        }
    }
    return ans;
}

int bfs(int cv, int& farV, int n){
    queue<pair<int, int>> Q;
    Q.push({cv, 0});
    vector<bool> vis(n, 0);
    vis[cv] = 1;
    int dis = 0;
    while(!Q.empty()){
        pair<int, int> p = Q.front();Q.pop();
        cv = p.first;
        for(int v: G[cv]){
            if(!vis[v]){
                Q.push({v, p.second+1});
                vis[v] = 1;
                if(dis < p.second+1){
                    farV = v;
                    dis = p.second+1;
                }
            }
        }
    }
    return dis;
}

int dia(int n){
    int farV, farV2;
    int diam = bfs(0, farV, n);
    diam = bfs(farV, farV2, n);
    return diam;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, a, da, b, db, _1, _2;
    string ans;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>da>>db;
        a--;b--;
        for(int i=0; i<n-1; i++){
            cin>>_1>>_2;
            _1--;_2--;
            G[_1].push_back(_2);
            G[_2].push_back(_1);
        }
        if(dfs(a, b, da) || min(db, dia(n)) <= 2*da){
            ans = "Alice";
        }
        else if(db >= 2*da){
            ans = "Bob";
        }
        cout<<ans<<"\n";
        for(int i=0; i<n; i++){
            G[i].clear();
        }
    }
}
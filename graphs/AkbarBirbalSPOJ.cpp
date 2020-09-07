#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int visited=0;
int main(){
    SPEED;
    int t, v, e, s, x, y;
    cin>>t;
    while(t--){
        visited=0;
        unordered_map<int,int> Strength;
        cin>>v>>e>>s;
        vector<int> adj[v+1];
        int vis[v+1];
        memset(vis, 0, sizeof(vis));
        int p[v+1];
        memset(p, 0, sizeof(p));

        while(e--){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        while(s--){
            cin>>x>>y;
            Strength[x] = y;
        }
        queue<pair<int,int>> Q;
        bool ans = true;
        for(auto itr:Strength){
            Q.push({itr.first, itr.second});
            vis[itr.first] = 1;visited++;
            p[itr.first] = itr.first;
        }
        int cv, str;
        pair<int,int> top;
        while(!Q.empty()){
            top = Q.front();Q.pop();
            cv = top.first;
            str = top.second;
            for(auto itr:adj[cv]){
                if(vis[itr] == 1 && p[itr] != p[cv]){
                    
                    Q = {};
                    break;
                }
                if(p[itr] == 0){
                    vis[itr] = 1;
                    p[itr] = p[cv];
                    visited++;
                    if(str>1){
                        Q.push({itr, str-1});
                    }
                }
            }
        }
        if(v==visited){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}
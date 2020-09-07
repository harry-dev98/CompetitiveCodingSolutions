#include<bits/stdc++.h>
using namespace std;


void in_dfs(vector<pair<long long int, long long int>> G[], long long int cv,  long long int in[], long long int nv[], bool vis[]){
    vis[cv] = true;
    nv[cv] = 1;
    in[cv] = 0;
    for(auto itr:G[cv]){
        if(vis[itr.first] == 0){
            in_dfs(G, itr.first, in, nv, vis);
            nv[cv] += nv[itr.first];
            in[cv] += in[itr.first]+(nv[itr.first]*itr.second);
        }
    }
}

int main(){
    long long int n, x, y, z;
    cin>>n;
    vector<pair<long long int, long long int>> G[n+1];
    for(long long int i=0; i<n-1; i++){
        cin>>x>>y>>z;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }
    long long int in[n+1];
    long long int out[n+1];
    long long int nv[n+1];
    bool vis[n+1];
    nv[0]=n;
    memset(vis, 0, sizeof(vis));
    in_dfs(G, 1, in, nv, vis);
    queue<pair<long long int,pair<long long int, long long int>>>Q;
    long long int P[n+1];
    P[1] = -1;
    Q.push({1,{-1, -1}});
    long long int cv, p, wt;
    pair<long long int,pair<long long int, long long int>> pair;
    memset(vis, 0, sizeof(vis));
    while(!Q.empty()){
        pair = Q.front();Q.pop();
        cv = pair.first;
        p = pair.second.first;
        wt = pair.second.second;
        vis[cv] = 1;
        out[cv] = 0;
        if(p != -1){
            long long int h = out[p];
            for(auto itr:G[p]){
                if(itr.first != P[p] && itr.first != cv){
                    h += (nv[itr.first])*itr.second + in[itr.first];
                }
            }
            out[cv] += (nv[0] - nv[cv])*wt + h;
        }
        for(auto itr:G[cv]){
            if(vis[itr.first] == 0){
                Q.push({itr.first, {cv, itr.second}});
                P[itr.first] = cv;
            }
        }
    }

    for(long long int i=1; i<n+1; i++){
        cout<<in[i]+out[i]<<" ";
    }
    cout<<"\n";
}
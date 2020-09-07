// two approaches covered here 1 is a mistake..
// Second has a bug.. 
//1. -> using SPFA (dijkstra) we find shortest path from one
// vertex. Also keeping tack of parent. then for each 2way road
// we check optimal path
//2. -> we consider 2-way roads during dijkstra.


#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

const int MXN = 10005;
#define pii pair<int,int>
vector<pii> G[MXN];
vector<pii> V[MXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt, n, m, k, s, t, a, b, w;
    cin>>tt;
    while(tt--){
        cin>>n>>m>>k>>s>>t;
        s--;t--;
        for(int i=0; i<m; i++){
            cin>>a>>b>>w;
            a--;b--;
            G[a].push_back({b, w});
        }
        for(int i=0; i<k; i++){
            cin>>a>>b>>w;
            a--;b--;
            V[a].push_back({b,w});
            V[b].push_back({a,w});
        }
        int dis[n];
        bool vis[n];
        for(int i=0; i<n; i++){
            vis[i] = 0;
            dis[i] = INT32_MAX;
        }
        dis[s] = 0;
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>pq;
        pq.push({0, {s, 0}});
        pair<int, pii> p;
        int f, cv, v;
        while(!pq.empty()){
            p = pq.top();pq.pop();
            cv = p.second.first;
            f = p.second.second;
            if(!vis[cv]){
                for(auto _:G[cv]){
                    v = _.first;
                    if(dis[v] > (dis[cv] + _.second)){
                        dis[v] = dis[cv]+_.second;
                        pq.push({dis[v], {v, f}});
                    }
                }
                if(f == 0){
                    for(auto _: V[cv]){
                        v = _.first;
                        if(dis[v] > (dis[cv] + _.second)){
                            dis[v] = dis[cv]+_.second;
                            pq.push({dis[v], {v, 1}});
                        }    
                    }
                }
                vis[cv] = 1;
            }
        }
        cv = t;
        int ans = dis[cv];
        // unordered_set<int>S = {cv};
        // while(cv != s){
        //     cv = P[cv];
        //     S.insert(cv);
        // }
        // for(auto v:V){
        //     if(S.find(v.first.first) != S.end() && S.find(v.first.second) != S.end()){
        //         int old = abs(dis[v.first.second] - dis[v.first.first]);
        //         int dif = old - v.second;
        //         if(dif > 0){
        //             ans = min(ans, dis[t] - dif);
        //         }
        //     }
        // }

        cout<<(ans==INT32_MAX?-1:ans)<<"\n";
        for(int i=0; i<n; i++){
            G[i].clear();
            V[i].clear();
        }
    }
    return 0;
}
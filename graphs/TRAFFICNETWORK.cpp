// We find shortest path from both start and end vertex
// using some SPFA then we try to optimise adding 2 way
// roads; Using a complementary graph obviously.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define pii pair<int, int>

const int inf = 1e9+9;

vector<int> dijkstra(int cv, int n, vector<pii> g[]){
    vector<int> dis(n, inf);
    // vector<bool> vis(n, 0);
    dis[cv] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, cv});
    int v;
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        cv = p.second;
        // if(!vis[cv]){
            for(auto _:g[cv]){
                v = _.first;
                if(dis[v] > p.first + _.second){
                    dis[v] = p.first + _.second;
                    pq.push({dis[v], v});
                }    
            }
            // vis[cv] = 1;
        // }
    }
    return dis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt, n, m, k, s, t, a, b, w;
    cin>>tt;
    while(tt--){
        cin>>n>>m>>k>>s>>t;
        s--; t--;

        vector<pii> G[n];
        vector<pii> G_[n];

        for(int i=0; i<m; i++){
            cin>>a>>b>>w;
            a--;b--;
            G[a].push_back({b, w});
            G_[b].push_back({a, w});
        }
        
        vector<int> disS = dijkstra(s, n, G);
        vector<int> disT = dijkstra(t, n, G_);

        int ans = disS[t];
        for(int i=0; i<k; i++){
            cin>>a>>b>>w;
            a--; b--;
            ans = min(ans, min(disS[a] + disT[b] + w, disS[b] + disT[a] + w));
        }
        cout<<(ans==inf?-1:ans)<<"\n";
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
#define pid pair<int, double>
#define pdi pair<double, int>
const int inf = 1e9+9;
const int N = 109;
vector<pid> Adj[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, wt;
    cin>>n;
    while(n!=0){
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b>>wt;
            a--; b--;
            Adj[a].push_back({b, (double)wt/100});
            Adj[b].push_back({a, (double)wt/100});
        }
        vector<double> dis(n, 0);
        vector<bool> vis(n, 0);
        vector<int> parent(n, -1);
        dis[0] = 1.0;
        priority_queue<pdi> pq;
        pq.push({dis[0], 0});
        pdi top; int cv, v;
        while(!pq.empty()){
            top = pq.top();pq.pop();
            cv = top.second;
            if(!vis[cv]){
                for(auto _:Adj[cv]){
                    v = _.first;
                    if(dis[v] < (top.first*_.second)){
                        dis[v] = (top.first*_.second);
                        pq.push({dis[v], v});
                        parent[v] = cv;
                    }
                }
                vis[cv] = 1;
            }
        }  
        cout<<fixed;
        cout<<setprecision(6)<<dis[n-1]*100<<" percent\n";
        for(int i=0; i<n; i++){
            Adj[i].clear();
        }
        cin>>n;
    }
    return 0;
}
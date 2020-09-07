#include<bits/stdc++.h>
using namespace std;

#define INF 10000000


vector<pair<int,int>> adj[1001];
int V, E;

int SPDijkstra(int cv, int end, priority_queue<pair<int,int>> &pq, bool vis[], int dis[], int prev[]){
    pq.push(make_pair(0,cv));
    dis[cv] = 0;
    while(!pq.empty()){
        cv = pq.top().second;
        vis[cv] = true;
        pq.pop();
        for(auto itr=adj[cv].begin();itr!=adj[cv].end();itr++){
            if(vis[itr->first]) continue;
            if(dis[itr->first]>dis[cv]+itr->second){
                dis[itr->first] = dis[cv]+itr->second;
                prev[itr->first] = cv;
                pq.push(make_pair(-1*dis[itr->first], itr->first));
            }
        }
    }
    return dis[end];
}

int main(){
    cin>>V>>E;int a,b,w;
    int dis[V+1], prev[V+1];
    bool vis[V+1];
    for(int i=1; i<=E; i++){
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b, w));
    }

    for(int i=1; i<=V; i++){
        dis[i]=INF;
        vis[i]=false;
        prev[i]=-1;
    }
    int start, end; cin>>start>>end;
    priority_queue<pair<int,int>> pq;
    int d = SPDijkstra(start, end, pq, vis, dis, prev);
    cout<<d<<"\n";
    cout<<"Shortest Path is ";
    stack<int> S;
    while(end!=-1){
        S.push(end);
        end = prev[end];
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int t = 0;
// 2 cases
// // i) v is root :-  if v being root has more than 1 childern, it is a articulate point.
// // ii) v is not root :- if any of the desendent of v has no back edge to any of ancestor
// //                       of v then v is articulate point. 
// //                       lowLink[v] >= disc[cv] => that the discovery time of parent is
// //                       is the least time to which vertex v could reach. i.e. v vertex
// //                       can never be reached before cv hence cv is only pathway to v. 
void dfs(int cv, int p, int lowLink[], int disc[], bool vis[], vector<int> G[], int &ans){
    vis[cv] = 1;
    lowLink[cv] = t;
    disc[cv] = t++;
    int childern = 0;
    bool isArtPt = 0;
    for(auto v:G[cv]){
        if(vis[v] == 0){
            dfs(v, cv, lowLink, disc, vis, G, ans);
            lowLink[cv] = min(lowLink[cv], lowLink[v]);
            if(lowLink[v] >= disc[cv] && p != -1){
                isArtPt = 1;
            }
            childern++;
        }
        else if(v!=p && vis[v] == 1){
            lowLink[cv] = min(lowLink[cv], disc[v]);
        }
    }
    if(childern>1 && p==-1){
        isArtPt = 1;
    }
    if(isArtPt)
        ans++;
}

int main(){
    int t, v, e, x, y;
    cin>>t;
    while(t--){
        cin>>v>>e;
        vector<int>G[v+1];
        for(int i=0; i<e; i++){
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int lowLink[v+1], disc[v+1];
        bool vis[v+1];
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i=1; i<=v; i++){
            if(vis[i]==0){
                dfs(i, -1, lowLink, disc, vis, G, ans);
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
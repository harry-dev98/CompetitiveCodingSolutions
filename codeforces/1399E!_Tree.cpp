#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
vector<pii>G[100007];
int ans = 0;
long long S;
void dfs(int cv, int p, vector<pii> V){
    int ch = 0;
    for(auto v:G[cv]){
        if(v.first != p){
            ch++;
            V.push_back({v.first, cv});
            dfs(v.first, cv, V);
        }
    }
    if(ch == 0){
        long long s = 0;
        for(auto c:V)s+=G[c.first];
        if(s>S){
            int i = 0;
            while(s>S && i<V.size()){
                s-= V[i].second/2;
                pii __ = G[V[i].second];
                __.second /= 2;
                G[V[i].second] = __;
                i++;
                ans++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, a, b, w;
        cin>>n>>S;
        for(int i=0; i<n-1; i++){
            cin>>a>>b>>w;
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }
        vector<pii>_;
        dfs(1, -1, _);
        cout<<ans<<"\n";
        for(int i=0; i<n; i++){
            G[i].clear();
        }
    }
    return 0;
}
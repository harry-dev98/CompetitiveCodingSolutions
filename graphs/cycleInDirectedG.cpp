#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool _isCyclic(int cv, vector<int> A[], bool vis[], bool inStack[]){
    vis[cv] = true; inStack[cv]=true; bool ans=false;
    for(auto v:A[cv]){
        if(inStack[v]){
            inStack[cv]=false;
            return true;
        }
        if(!vis[v]){
            ans |= _isCyclic(v, A, vis, inStack);
            // cout<<ans<<cv<<v<<"\n";
        }
    }
    inStack[cv]=false;
    return ans;
}

bool isCyclic(int v, vector<int> A[]){
    bool vis[v], inStack[v];
    memset(vis, 0, sizeof(vis));
    memset(inStack, 0, sizeof(inStack));
    bool ans = false;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            ans |= _isCyclic(i, A, vis, inStack);
        }
    }
    return ans;
}

int main(){
    SPEED;
    int V, E;
    int t, x, y; cin>>t;
    while(t--){
        cin>>V>>E;
        vector<int> A[V];
        for(int i=0; i<E; i++){
            cin>>x>>y;
            A[x].push_back(y);
        }
        if(isCyclic(V, A)){
            cout<<"cyclic\n";
        }
        else{
            cout<<"notCyclic\n";
        }
    }
    return 0;
}
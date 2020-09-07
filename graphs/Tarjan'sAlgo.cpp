#include<bits/stdc++.h>
using namespace std;

void print_SCC(stack<int>&S, int cv, int lowlink[], int disc[], bool instack[]){
    int top;
    vector<int>SSC;
    while(!S.empty()){
        top = S.top();
        if(lowlink[top]!=disc[cv]){
            break;
        }
        SSC.push_back(top);
        instack[top] = 0;
        S.pop();
    }
    int size = SSC.size();
    for(int i=0; i<size; i++){
        cout<<SSC[i];
        if(i!=size-1){
            cout<<" ";
        }
        else{
            cout<<",";
        }
    }
}
int d=0;

void dfs_tarjansalgo(int cv, bool vis[], bool instack[], int lowlink[], int disc[], stack<int>&S, vector<int>adj[]){
    vis[cv] = 1;
    instack[cv] = 1;
    disc[cv] = d++;
    S.push(cv);
    for(auto v:adj[cv]){
        lowlink[v] = v;
        if(vis[v] == 0){
            dfs_tarjansalgo(v, vis, instack, lowlink, disc, S, adj);
        }
        if(instack[v]){
            lowlink[cv] = min(lowlink[cv], lowlink[v]);

        }
    }
    if(lowlink[cv] == cv){
        print_SCC(S, cv, lowlink, disc, instack);
    }
}

int main(){
    int t, v, e, x, y;
    cin>>t;
    while(t--){
        cin>>v>>e;
        vector<int>adj[v];
        for(int i=0; i<e; i++){
            cin>>x>>y;
            adj[x].push_back(y);
        }
        bool vis[v];
        bool instack[v];
        memset(instack, 0, sizeof(instack));
        memset(vis, 0, sizeof(vis));
        int lowlink[v];
        int disc[v];
        stack<int>S;
        
        for(int i=0; i<v; i++){
            if(vis[i] == 0){
                lowlink[i] = i;
                dfs_tarjansalgo(i, vis, disc, instack, lowlink, S, adj);
            }
        }
        cout<<"\n";
    }
    return 0;
}
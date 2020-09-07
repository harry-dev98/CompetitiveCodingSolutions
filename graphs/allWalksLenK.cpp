#include<bits/stdc++.h>
using namespace std;

int G[21][21];
int V, u, v, k;

int paths(int u, int v, int k){
    if(k==0 && u==v){
        return 1;
    }
    if(k==1 && G[u][v]==1){
        return 1;
    }
    if(k==0){
        return 0;
    }
    int count = 0;
    for(int i=0; i<V; i++){
        if(G[u][i]==1){
            count += paths(i, v, k-1);  
            // cout<<count<<endl;  
        }
    }
    return count;
}

int paths_optimised(int u, int v, int k){
    vector<vector<int>> DP(21, vector<int>(k+1, 0));
    DP[u][0]=1; // initalising only required one.. we say from u we have 0 lenght one walk..
    for(int i=1; i<=k; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                if(G[j][k]==1){
                    DP[k][i] += DP[j][i-1];
                }
            }
        }
    }
    return DP[v][k];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cin>>G[i][j];
            }
        }
        cin>>u>>v>>k;
        cout<<paths_optimised(u, v, k)<<"\n";
    }
}
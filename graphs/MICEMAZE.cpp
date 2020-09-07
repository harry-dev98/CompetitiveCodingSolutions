#include<iostream>
using namespace std;

int G[109][109];
int main(){
    int n, d, t, m, a, b, w;
    cin>>n>>d>>t>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            G[i][j] = 100000009;
        }
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>w;a--;b--;
        G[a][b] = w;
    }
    for(int i=0; i<n; i++){
        G[i][i] = 0;
    }
    d--;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(G[i][d] <= t){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
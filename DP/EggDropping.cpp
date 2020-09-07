#include<bits/stdc++.h>
using namespace std;
//n -> no of floors
//k -> no. of eggs
int EggDrop(int n, int k){
    int DP[k+1][n+1];
    memset(DP, 0, sizeof(DP));
    for(int i=1; i<=n; i++){
        DP[1][i] = i;
    }
    for(int i=1; i<=k; i++){
        DP[i][1] = 1;
    }
    for(int i=2; i<=k; i++){
        for(int j=2; j<=n; j++){
            DP[i][j] = 1000001;
            for(int k_=1; k_<=j; k_++){
                DP[i][j] = min(DP[i][j], 1 + max(DP[i-1][k_-1], DP[i][j-k_]));
            }
        }
    }
    return DP[k][n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        cout<<EggDrop(k, n)<<"\n";
    }
    return 0;
}
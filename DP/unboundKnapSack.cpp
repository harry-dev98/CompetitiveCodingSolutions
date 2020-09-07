#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int Memo[105][105];

int UnboundedKnapSackMemo(int val[], int wt[], int n, int w){
    if(n == 0 || w == 0)return 0;
    if(Memo[n][w]!=-1)return Memo[n][w];
    if(w<wt[n-1]){
        return Memo[n][w] = UnboundedKnapSackMemo(val, wt, n-1, w);
    }
    else{
        return Memo[n][w] = max(UnboundedKnapSackMemo(val, wt, n, w - wt[n-1])+val[n-1], UnboundedKnapSackMemo(val, wt, n-1, w));
    }
}

int UnboundedKnapSackDP(int val[], int wt[], int n, int w){
    int DP[n+1][w+1];
    memset(DP, 0, sizeof(DP));
    for(int i=0; i<=n; i++)DP[i][0] = 0;
    for(int i=0; i<=w; i++)DP[0][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j<wt[i-1]){
                DP[i][j] = DP[i-1][j];
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    return DP[n][w];
}

int main(){
    SPEED;
    int t;
    cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        int val[n], wt[n];
        for(int i=0; i<n; i++){
            cin>>val[i];
        }
        for(int i=0; i<n; i++){
            cin>>wt[i];
        }
        memset(Memo, -1, sizeof(Memo));
        cout
        <<UnboundedKnapSackMemo(val, wt, n, w)<<" "
        <<UnboundedKnapSackDP(val, wt, n, w)
        <<"\n";
    }
}
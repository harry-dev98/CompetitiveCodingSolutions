    #include<bits/stdc++.h>
    using namespace std;


    int KnapSackRec(int wt[], int val[], int n, int w){
        if(n==0 || w == 0){
            return 0;
        }
        int w_ = wt[n-1];
        if(w_<=w){
            return max(val[n-1]+KnapSackRec(wt, val, n-1, w-w_),
                KnapSackRec(wt, val, n-1, w));
        }
        else{
            return KnapSackRec(wt, val, n-1, w);
        }
    }
    int DP_memo[1005][1005];
    int DP[1005][1005];
    int KnapSackMemo(int wt[], int val[], int n, int w){
        if(n == 0 || w == 0){
            return 0;
        }
        if(DP_memo[n][w] != -1)return DP_memo[n][w];
        return DP_memo[n][w] = (wt[n-1]<=w)?max(KnapSackMemo(wt, val, n-1, w), val[n-1]+KnapSackMemo(wt, val, n-1, w-wt[n-1])):KnapSackMemo(wt, val, n-1, w);
    }
    int KnapSackTopDown(int wt[], int val[], int n, int w){
        for(int i=0; i<=n; i++){
            DP[i][0] = 0;
        }
        for(int i=0; i<=w; i++){
            DP[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                DP[i][j] = (wt[i-1]<=j)?max(val[i-1] + DP[i-1][j-wt[i-1]], DP[i-1][j]):DP[i-1][j];
            }
        }
        return DP[n][w];
    }

    int main(){
        int t;
        cin>>t;
        while(t--){
            memset(DP_memo, -1, sizeof(DP_memo));
            memset(DP, -1, sizeof(DP));
            int n, w;cin>>n>>w;
            int wt[n], val[n];
            for(int i=0; i<n; i++){
                cin>>wt[i];
            }
            for(int i=0; i<n; i++){
                cin>>val[i];
            }
            cout<<KnapSackRec(wt, val, n, w)<<" "
            <<KnapSackMemo(wt, val, n, w)<<" "
            <<KnapSackTopDown(wt, val, n, w)<<"\n";
        }
    }
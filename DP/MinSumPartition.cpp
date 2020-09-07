#include<bits/stdc++.h>
using namespace std;

int MinSubsetSumTopDown(int A[], int n, int S){
    bool DP[n+1][S+1];
    for(int i=0; i<=n; i++){
        DP[i][0] = 1;
    }
    for(int i=1; i<=S; i++){
        DP[0][i] = 0;
    }
    int a;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=S; j++){
            a = A[i-1];
            DP[i][j] = (j>=a)?DP[i-1][j] || DP[i-1][j-a]:DP[i-1][j];
        }
    }
    int mnn = 1000007;
    for(int i=1; i<=S/2; i++){
        if(DP[n][i]){
            mnn = min(mnn, abs(S - 2*i));
        }
    }
    return mnn;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,S=0;cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
            S+=A[i];
        }
        cout<<MinSubsetSumTopDown(A, n, S)<<"\n";
    }
}
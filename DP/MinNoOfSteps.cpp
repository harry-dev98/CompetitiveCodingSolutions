#include<bits/stdc++.h>
using namespace std;


int MinStepsRec(int A[], int n, int itr){
    if(n-1<=itr){
        return 0;
    }
    if(A[itr]!=0){
        int ans = 1000007;
        for(int i=A[itr]; i>0; i--){
            ans = min(ans, MinStepsRec(A, n, itr+i));
        }
        return 1 + ans;
    }
    else{
        return 1000007;
    }
}
int DP_memo[10005];
int DP[10005];
int MinStepsMemo(int A[], int n, int itr){
    if(n <= itr){
        return 0;
    }
    if(DP_memo[itr] != 1000007)return DP_memo[itr];
    if(A[itr]!=0){
        int ans = 1000007;
        for(int i=itr+1; i<n; i++){
            if(itr+A[itr] >= i)
            ans = min(ans, MinStepsRec(A, n, i));
        }
        return DP[itr] = 1 + ans;
    }
    else{
        return DP[itr] = 1000007;
    }
}
int MinStepsTopDown(int A[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(j+A[j]>=i)
                DP[i] = min(DP[j]+1, DP[i]);
            // cout<<DP[i]<<" ";
        }
        // cout<<"\n";
    }
    return DP[n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<10005; i++){
            DP[i] = 1000007;
            DP_memo[i] = 1000007;
        }
        int n;cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        DP[0] = 0;
        cout
        // <<MinStepsRec(A, n, 0)<<" "
        <<MinStepsMemo(A, n, 0)<<" "
        <<MinStepsTopDown(A, n)
        <<"\n";
    }
}
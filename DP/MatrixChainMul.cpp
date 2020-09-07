#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll Memo[107][107];

ll MCM(int A[], int i, int j){
    if(i==j){
        return 0;
    }
    if(i>j){
        return 0;
    }
    if(Memo[i][j] != -1)return Memo[i][j];
    ll mnn = 1e18;
    for(int k=i; k<j; k++){
        ll one = (Memo[i][k]!=-1)?Memo[i][k]:MCM(A, i, k);
        ll two = (Memo[k+1][j]!=-1)?Memo[k+1][j]:MCM(A, k+1, j);
        mnn = min(one+two+A[i-1]*A[k]*A[j], mnn);
    }
    return Memo[i][j] = mnn;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        memset(Memo, -1, sizeof(Memo));
        cout<<MCM(A, 1, n-1)<<"\n";
    }
    return 0;
}
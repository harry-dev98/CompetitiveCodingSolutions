#include<bits/stdc++.h>
using namespace std;

int SkipWork(int A[], int n){
    int inc[n], exc[n];
    inc[0] = A[0];
    exc[0] = 0;
    for(int i=1; i<n; i++){
        // DP[i] = min(include(i), exclude(i))
        // include i
        inc[i] = A[i] + min(inc[i-1], exc[i-1]);
        exc[i] = inc[i-1];
        
    }
    return min(exc[n-1], inc[n-1]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cout<<SkipWork(A, n)<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long> A(n);
        for(long long& a: A)cin>>a;
        long long minOp = 0, opCanBAvoided = 0;
        for(int i=1; i<n; i++){
            minOp += abs(A[i] - A[i-1]);
        }
        opCanBAvoided = max(abs(A[0]-A[1]), abs(A[n-2]-A[n-1]));
        for(int i=1; i<n-1; i++){
            opCanBAvoided = max(opCanBAvoided, abs(A[i]-A[i-1]) +  abs(A[i]-A[i+1]) - abs(A[i-1]-A[i+1]));
        }
        cout<<minOp-opCanBAvoided<<"\n";
    }
    return 0;
}
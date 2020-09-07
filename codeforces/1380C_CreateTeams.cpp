#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        sort(A, A+n);
        int ans;
        for(int i=0; i<n; i++){
            int tmp = k/A[i];
        }
    }
}
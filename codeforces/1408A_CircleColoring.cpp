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
        int A[n], B[n], C[n], D[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=0; i<n; i++)cin>>B[i];
        for(int i=0; i<n; i++)cin>>C[i];
        D[0] = A[0];
        for(int i=1; i<n; i++){
            if(A[i] != D[i-1]){
                D[i] = A[i];
            }
            else if(B[i] != D[i-1]){
                D[i] = B[i];
            }
            else{
                D[i] = C[i];
            }
        }
        if(D[0] == D[n-1])
        if(A[n-1] != D[0]){
            D[n-1] = A[n-1];
        }
        else if(B[n-1] != D[0]){
            D[n-1] = B[n-1];
        }
        else{
            D[n-1] = C[n-1];
        }
        for(int i=0;i<n;i++)cout<<D[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
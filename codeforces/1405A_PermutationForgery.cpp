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
        int A[n];
        for(int i=0; i<n; i++)cin>>A[i];
        for(int i=n-1; i>n/2; i--)cout<<A[i]<<" ";
        for(int i=n/2; i>=0; i--)cout<<A[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
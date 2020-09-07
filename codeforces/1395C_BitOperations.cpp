#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int A[n], B[m];
    for(int i=0; i<n; i++)cin>>A[i];
    for(int i=0; i<m; i++)cin>>B[i];
    int ans = 0, x = 0;
    for(int i=0; i<n; i++){
        int _ = (1<<9)+1;
        for(int j=0; j<m; j++){
            // _ = min(_, A[i]&B[j]);
            _ = min(_, A[i]^B[j]);
        }
        cout<<ans<<"-\n";
        ans = ans | _;
    }
    cout<<ans<<"\n";
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        int prev = A[0];
        int ans = n;
        for(int i=1; i<n; i++){
            if(A[i] != prev){
                ans = 1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
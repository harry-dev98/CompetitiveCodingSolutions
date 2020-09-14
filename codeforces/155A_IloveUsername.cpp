#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, mn, mx, ans = 0;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    mn = A[0];
    mx = A[0];
    for(int i=1; i<n; i++){
        if(mn>A[i]){
            mn = A[i];
            ans++;
        }
        if(mx<A[i]){
            mx = A[i];
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
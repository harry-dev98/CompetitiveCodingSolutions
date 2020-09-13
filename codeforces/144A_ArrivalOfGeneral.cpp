#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int mn = 1e9;
    int ind1;
    for(int i=0; i<n; i++){
        if(A[i] <= mn){
            mn = A[i];
            ind1 = i;
        }
    }
    int ind2;
    int mx = 0;
    for(int i=0; i<n; i++){
        if(A[i]>mx){
            mx = A[i];
            ind2 = i;
        }
    }
    int ans = ind2 + n - ind1 - 1;
    if(ind2 > ind1){
        ans--;
    }
    cout<<ans<<"\n";
    return 0;
}
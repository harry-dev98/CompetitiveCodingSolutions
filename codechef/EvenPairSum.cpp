#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<(ll)((a/2)*(b/2)) + (ll)(((a+1)/2) * ((b+1)/2))<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t, x, y, k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        ll sticksReq =  (y + 1) * k;
        ll deals = k + (sticksReq - 1 + x - 2)/(x-1);
        cout<<deals<<"\n"; 
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, s, p, v;
    cin>>t;
    while(t--){
        cin>>n; int ans = 0;
        while(n--){
            cin>>s>>p>>v;
            ans = max(v * (p/(s+1)), ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
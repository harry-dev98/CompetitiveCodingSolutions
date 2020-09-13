#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    double ans = 0.0, _;
    for(int i=0; i<n; i++){
        cin>>_;
        ans += _;
    }
    ans /= n;
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}
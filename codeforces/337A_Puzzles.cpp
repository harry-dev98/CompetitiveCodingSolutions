#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin>>n>>p;
    vector<int> P(p);
    for(int& _: P)cin>>_;
    sort(P.begin(), P.end());
    int ans = 1e9+7;
    for(int i=0; i<=p-n; i++){
        ans = min(ans, P[i+n-1] - P[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
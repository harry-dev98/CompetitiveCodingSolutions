#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, a, b, x, y, n;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y>>n;
        long long dif = a-x + b-y;
        long long ans = 9e18+1;
        if(a-x < n){
            ans = min(ans, x*max(y, n - (a-x)));
        }
        else{
            ans = min(ans, a-n * b);
        }
        if(b-y < n){
            ans = min(ans, y*max(x, n - (b-y)));
        }
        else{
            ans = min(ans, b-n * a);
        }
        // ans = min(ans, (a-n/2)*(b-(n+1)/2));
        // ans = min(ans, (a-(n+1)/2) - (b-n/2));
        cout<<ans<<"\n";
    }
    return 0;
}
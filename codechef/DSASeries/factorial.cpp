#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 0;
        for(int div=5; n/div>=1; div*=5){
            ans += n/div;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
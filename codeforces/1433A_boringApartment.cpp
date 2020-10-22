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
        int last = n%10;
        int digs = 0;
        while(n){
            digs++;
            n /= 10;
        }
        ans += (last-1)*10;
        if(digs == 1)ans += 1;
        else if(digs == 2)ans += 3;
        else if(digs == 3)ans += 6;
        else ans += 10;
        cout<<ans<<"\n";
    }
    return 0;
}
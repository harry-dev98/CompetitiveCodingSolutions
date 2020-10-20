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
        vector<int> Speed(n);
        for(int& s: Speed)cin>>s;
        int ans = 1;
        for(int i=1; i<n; i++){
            if(Speed[i] < Speed[i-1]){
                ans++;
            } else {
                Speed[i] = Speed[i-1];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s, ans;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        ans = "";
        for(int i=0; i<n; i++){
            ans+=s[n-1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
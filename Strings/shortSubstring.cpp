#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, ans="";
        cin>>s;
        int n = s.length();
        ans += s[0];
        for(int i=1; i<n-1; i+=2){
            ans+=s[i];
        }
        ans+=s[n-1];
        cout<<ans<<"\n";
    }
    return 0;
}
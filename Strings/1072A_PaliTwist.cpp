#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    bool ans;
    cin>>t;
    while(t--){
        cin>>n>>s;
        ans = true;
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-1-i] && abs(s[i]-s[n-1-i])!=2){
                ans = false;
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
}
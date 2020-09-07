#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    string ans = "";
    if(n%2){
        for(int i=0; i<n-1; i+=2){
            ans = ans + s[i];
            ans = s[i+1] + ans;
        }
        ans+=s[n-1];
        
    }
    else{
        for(int i=0; i<n-1; i+=2){
            ans = ans + s[i+1];
            ans = s[i] + ans;
        }
        
    }
    cout<<ans<<"\n";
    return 0;
}
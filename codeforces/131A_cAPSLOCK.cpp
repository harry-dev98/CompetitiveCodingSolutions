#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = "";
    cin>>s;
    int up = 0;
    
    for(auto _: s){
        if(_ >= 'A' && _ <= 'Z'){
            up++;
        }
    }
    int n = s.size();
    if(up == n){
        for(int i=0; i<n; i++){
            ans += (char)tolower(s[i]);
        }
    }else if(up == n-1 && s[0] >= 'a' && s[0] <= 'z'){
        ans += (char)toupper(s[0]);
        for(int i=1; i<n; i++){
            ans += (char)tolower(s[i]);
        }
    }
    else{
        ans = s;
    }
    cout<<ans<<"\n";
    return 0;
}
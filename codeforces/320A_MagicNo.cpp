#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool ans = true;
    for(int i=0; i<n; i++){
        if(s[i] != '1' && s[i] != '4'){
            ans = false;
            break;
        }
    }
    if(s[0] != '1')ans=false;
    for(int i=0; i<=n-3; i++){
        if(s.substr(i, 3) == "444"){
            ans = false;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}
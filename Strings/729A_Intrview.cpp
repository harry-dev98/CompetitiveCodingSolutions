#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    string ans = "";
    for(int i=0; i<n; i++){
        while(s.substr(i, 3)=="ogo"){
            i += 3;
            ans += "***";
            while(s.substr(i, 2) == "go"){
                i+=2;
            }
            // i--;
        }
        if(i>=n)break;
        ans+=s[i];
    }
    cout<<ans<<"\n";
    return 0;
}
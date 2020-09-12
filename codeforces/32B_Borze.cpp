#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; 
    cin>>s;
    string ans = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '.'){
            ans += '0';
        }
        else{
            if(s[i+1] == '.'){
                ans += '1';
            } 
            else{
                ans += '2';
            }
            i++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
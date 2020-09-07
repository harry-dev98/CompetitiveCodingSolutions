#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a=0;
    string s, ans="";
    cin>>n>>s;
    for(int i=0; i<n; i+=2){
        char ch = s[i];
        if(s[i]==s[i+1]){
            int ch_ = 1 - (s[i]-'a');
            ch = ch_ + 'a';
            a++;
        }
        ans+=ch;
        ans+=s[i+1];
    }
    cout<<a<<"\n"<<ans<<"\n";
    return 0;
}
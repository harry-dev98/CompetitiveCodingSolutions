#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_set<char> S;
    for(auto ch:s){
        S.insert(ch);
    }
    string ans = (S.size()%2)?"IGNORE HIM!":"CHAT WITH HER!";
    cout<<ans<<"\n";
    return 0;
}
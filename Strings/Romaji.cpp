#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
    int n = s.length();
    bool ans = true;
    for(int i=0; i<n; i++){
        if(S.find(s[i]) != S.end() || s[i] == 'n')continue;
        if(S.find(s[i+1])==S.end() && s[i]!='n'){
            ans = false;
            break;
        }
    }   
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}
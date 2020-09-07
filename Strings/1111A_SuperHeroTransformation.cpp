#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, ss;
    cin>>s>>ss;
    unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
    int n = s.length();
    int nn = ss.length();
    bool ans = true;
    if(n!=nn){
        ans = false;
    }
    else{
        for(int i=0; i<n; i++){
            if((S.find(s[i]) != S.end() && S.find(ss[i]) == S.end())
            ||
            (S.find(s[i]) == S.end() && S.find(ss[i]) != S.end())){
                ans = false;
                break;
            }
        }
    }
    cout<<(ans?"Yes":"No")<<"\n";
    return 0;
}
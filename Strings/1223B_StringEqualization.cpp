#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s1, s2;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        unordered_set<char> S1, S2;
        for(auto s:s1){
            S1.insert(s);
        }
        for(auto s:s2){
            S2.insert(s);
        }
        bool f = false;
        for(auto s:S1){
            if(S2.find(s) != S2.end()){
                f = true;
                break;
            }
        }
        cout<<(f?"YES\n":"NO\n");
    }
    return 0;
}
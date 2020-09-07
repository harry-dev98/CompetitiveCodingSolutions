#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    unordered_set<string> S;
    unordered_set<char> S_;
    while(t--){
        S_ = {};
        cin>>s;
        for(auto ch:s){
            S_.insert(ch);
        }
        string tmp_s = "";
        for(auto ch:S_){
            tmp_s += ch;
        }
        sort(tmp_s.begin(), tmp_s.end());
        S.insert(tmp_s);
    }
    cout<<S.size()<<"\n";
    return 0;
}

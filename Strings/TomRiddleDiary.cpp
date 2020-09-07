#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    string s;
    set<string>S;
    vector<string>Ans;
    cin>>t;
    while(t--){
        cin>>s;
        if(S.find(s)==S.end()){
            S.insert(s);
            Ans.push_back("NO");
        }
        else{
            Ans.push_back("YES");
        }
    }
    for(auto s:Ans){
        cout<<s<<"\n";
    }
    return 0;
}
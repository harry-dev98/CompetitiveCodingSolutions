#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s1, s2;
    cin>>n>>m;
    unordered_map<string, string> M;
    for(int i=0; i<m; i++){
        cin>>s1>>s2;
        M[s1] = s2;
    }
    vector<string> V;
    for(int i=0; i<n; i++){
        cin>>s1;
        auto p = M.find(s1);
        if(p->first.length() > p->second.length()){
            V.push_back(p->second);
        }
        else{
            V.push_back(p->first);
        }
    }
    for(auto c:V){
        cout<<c<<" ";
    }
    cout<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    unordered_map<char, int> M;
    for(auto c:s){
        M[c]++;
    }
    int ans = 0;
    for(auto m:M){
        ans += m.second;
    }
    ans -= M.size();
    cout<<ans<<"\n";
    return 0;
}
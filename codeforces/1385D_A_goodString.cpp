#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

// long long POW[20];
int ans(const string &s, int l, int r, int d){ //}, unordered_map<string, int> &M){
    // long long rep=0;
    char c = 'a' + d;
    if(l+1==r)return (s[l] != c);
    int part = (l + r)/2;
    pair<pair<int,int>,pair<int,int>> _ = {{0, 0}, {0, 0}};
    for(int i=l; i<part; i++){
        if(s[i] != c){
            _.first.first++;
        }
    }
    for(int i=part; i<r; i++){
        if(s[i] != c){
            _.second.first++;
        }
        // rep += s[i]-c;
    }
    // if(M.find(rep) != M.end())return M[rep];
    _.first.second = ans(s, l, part, d+1);
    _.second.second = ans(s, part, r, d+1);
    // cout<<rep.length()<<" "<<l<<" "<<r<<"\n";
    return min(_.first.first+_.second.second, _.first.second+_.second.first);
}
// int M = 10000000000000009;
string s;
int main(){
    speed;
    int t, n;
    cin>>t;
    // POW[0] = 1;
    // for(int i=1; i<20; i++){
    //     POW[i] = (POW[i-1] * 20)%M;
    // }
    while(t--){
        cin>>n>>s;
        // unordered_map<string, int>M;
        cout<<ans(s, 0, n, 0)<<"\n";
    }
    return 0;
}
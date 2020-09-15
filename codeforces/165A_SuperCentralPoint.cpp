#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    cin>>n;
    vector<pair<int, int>> V;
    // unordered_map<int, pair<int, int>> M;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        V.push_back({x, y});
        // if(M.find(x) != M.end()){
        //     M[x].first = min(M[x].first, y);
        //     M[x].second = max(M[x].second, y);
        // }
        // else{
        //     M[x] = {y, y};
        // }
        // if(M.find(y) != M.end()){
        //     M[y].first = min(M[y].first, x);
        //     M[y].second = max(M[y].second, x);
        // }
        // else{
        //     M[y] = {x, x};
        // }
    }
    int ans = 0;
    for(auto v: V){
        // if(M[v.first].first < v.second &&
        // M[v.first].second > v.second &&
        // M[v.second].first < v.first &&
        // M[v.second].second > v.first){
        //     ans++;
        // }
        bool l = 0, r = 0, up = 0, d = 0;
        for(auto u: V){
            if(u.first == v.first && u.second > v.second)up=1;
            else if(u.first == v.first && u.second < v.second)d=1;
            else if(u.first > v.first && u.second == v.second)r=1;
            else if(u.first < v.first && u.second == v.second)l=1;
        }
        if(l && r && up && d)ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
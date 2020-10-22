#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>Gangs(n);
        for(int& b:Gangs)cin>>b;
        unordered_map<int, unordered_set<int>>M;
        for(int itr=0; itr<n; itr++){
            M[Gangs[itr]].insert(itr+1);
        }
        vector<pair<int, int>> Edges;
        for(auto itr: M){
            if(itr.second.find(1) == itr.second.end()){
                for(auto v: itr.second)Edges.push_back({1, v});
            }
        }
        M[Gangs[0]].erase(1);
        for(int i=2; i<=n; i++){
            if(M[Gangs[0]].find(i) == M[Gangs[0]].end()){
                for(auto v: M[Gangs[0]])Edges.push_back({i, v});
                break;
            }
        }
        cout<<(M.size()>1?"YES":"NO")<<"\n";
        if(M.size()>1){
            for(auto itr: Edges){
                cout<<itr.first<<" "<<itr.second<<"\n";
            }
        }
    }
    return 0;
}
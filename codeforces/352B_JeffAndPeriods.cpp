#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> Seq(n);
    for(int& s: Seq)cin>>s;
    vector<pair<int, int>> ans;
    unordered_map<int, vector<int>> M;
    for(int i=0; i<n; i++){
        M[Seq[i]].push_back(i+1);
    }
    for(auto m: M){
        if(m.second.size() == 1){
            ans.push_back({m.first, 0});
        }
        else{
            int dif = m.second[1] - m.second[0];
            bool f = 1;
            for(int i=1; i<m.second.size(); i++){
                if(m.second[i]-m.second[i-1] != dif)f=0;
            }
            if(f == 1){
                ans.push_back({m.first, dif});
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto a: ans){
        cout<<a.first<<" "<<a.second<<"\n";
    }
    return 0;
}
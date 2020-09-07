#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second;
}

int main(){
    int t;
    string s;
    cin>>t;
    unordered_map<string, int> M;
    while(t--){
        cin>>s;
        M[s]++;
    }
    auto mxele = max_element(M.begin(), M.end(), comp);
    cout<<mxele->first<<"\n";
    return 0;
}
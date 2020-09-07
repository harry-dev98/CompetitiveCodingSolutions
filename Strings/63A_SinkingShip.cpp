#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string, pair<int, int>>p1, pair<string, pair<int, int>>p2){
    if(p1.second.first == p2.second.first){
        return p1.second.second<p2.second.second;
    }
    return p1.second.first<p2.second.first;
}

int main(){
    unordered_map<string, int> M = {{"rat", 1}, {"woman", 2}, {"child", 2}, {"man", 3}, {"captain", 4}};
    int t;
    cin>>t;
    string s1, s2;
    vector<pair<string, pair<int, int>>> V;
    for(int i=0; i<t; i++){
        cin>>s1>>s2;
        V.push_back({s1, {M[s2], i}});
    }
    sort(V.begin(), V.end(), comp);
    for(auto ch:V){
        cout<<ch.first<<"\n";
    }
    return 0;
}
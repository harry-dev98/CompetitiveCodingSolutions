#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second;
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    unordered_map<string, int>M;
    for(int i=0; i<n-1; i++){
        M[s.substr(i, 2)]++;
    }
    pair<string, int> p = *max_element(M.begin(), M.end(), comp);
    cout<<p.first<<"\n";
    return 0;
}
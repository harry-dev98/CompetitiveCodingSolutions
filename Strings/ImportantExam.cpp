#include<bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2){
    return p1.second<p2.second;
}

int main(){
    int n, m;
    cin>>n>>m;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int a[m];
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    unordered_map<char, int> M[m];
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            M[j][s[i][j]]++;
        }
    }
    for(int i=0; i<m; i++){
        pair<char, int> p = *max_element(M[i].begin(), M[i].end(), comp);
        ans += p.second*a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
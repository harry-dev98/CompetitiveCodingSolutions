#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    string k, v;
    unordered_map<string, string>M;
    for(int i=0; i<n; i++){
        cin>>v>>k;
        M[k] = v;
    }
    string K[m], V[m];
    for(int i=0; i<m; i++){
        cin>>V[i]>>K[i];
    }
    for(int i=0; i<m; i++){
        cout<<V[i]<<" "<<K[i]<<" #"<<M[K[i].substr(0, K[i].length()-1)]<<"\n";
    }
    return 0;
}
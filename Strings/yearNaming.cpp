#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, x;
    cin>>n>>m;
    string N[n+1], M[m+1];
    for(int i=1; i<=n; i++){
        cin>>N[i];
    }
    for(int i=1; i<=m; i++){
        cin>>M[i];
    }
    M[0] = M[m];
    N[0] = N[n];
    cin>>k;
    while(k--){
        cin>>x;
        cout<<N[x%n]+M[x%m]<<"\n";
    }
    return 0;
}
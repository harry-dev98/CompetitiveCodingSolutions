#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    vector<long long> A(n);
    for(long long& a: A)cin>>a;
    unordered_map<long long, pair<long long, long long>> M;
    for(long long i=0; i<n; i++){
        M[A[i]] = {i + 1, n - i};
    }
    long long m;
    cin>>m;
    long long q, a=0, b=0;
    for(long long i=0; i<m; i++){
        cin>>q;
        a += M[q].first;
        b += M[q].second; 
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    string s;
    cin>>n>>k>>s;
    vector<int>A(k, 0);
    for(auto ch:s){
        A[ch-'A']++;
    }
    int ans = *min_element(A.begin(), A.end());
    cout<<k*ans<<"\n";
    return 0;
}
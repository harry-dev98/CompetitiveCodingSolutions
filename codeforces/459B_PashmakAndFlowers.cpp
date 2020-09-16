#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> Beauty(n);
    for(auto& b: Beauty)cin>>b;
    map<long long, long long> M;
    for(auto b: Beauty){
        M[b]++;
    }
    cout<<((--M.end())->first - M.begin()->first)<<" ";
    cout<<(M.size()==1?(M.begin()->second*(M.begin()->second-1))/2:(--M.end())->second * M.begin()->second)<<"\n";
    return 0;
}
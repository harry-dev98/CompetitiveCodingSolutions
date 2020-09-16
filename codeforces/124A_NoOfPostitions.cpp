#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    unordered_set<int> S;
    cout<<min(n-a, b+1)<<"\n";
    return 0;
}
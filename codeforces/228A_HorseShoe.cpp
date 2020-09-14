#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    unordered_set<int> S = {a, b, c, d};
    cout<<4-S.size()<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    l *= k;
    nl *= n;
    np *= n;
    int toast = min(l/nl, min(p/np, (c*d)/n));
    cout<<toast<<"\n";
    return 0;
}
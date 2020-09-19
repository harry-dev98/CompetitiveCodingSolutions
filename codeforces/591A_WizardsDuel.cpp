#include<bits/stdc++.h>
using namespace std;

int main(){
    double l, p, q;
    cin>>l>>p>>q;
    double ans = p * (l / (p + q));
    cout<<ans<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r, l_=0, r_ = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        l_ += l;
        r_ += r;
    }
    cout<<min(l_, n-l_)+min(r_, n-r_)<<"\n";
    return 0;
}
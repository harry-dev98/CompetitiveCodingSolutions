#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    int ans = 0, burntleftover = 0;
    while(a){
        ans += a;
        a += burntleftover;
        burntleftover = a % b;
        a /= b;
    }
    cout<<ans<<"\n";
    return 0;
}
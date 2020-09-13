#include<bits/stdc++.h>
using namespace std;

long long ans(long long x, long long a, long long b, long long c)
{
    long long res = x % c;
    for(long long i=0; i<b; i++){
        res = ((res-1LL) * a) % c;
    }
    return (res+c)%c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long x, a, n, c;
    cin>>x>>a>>n>>c;
    while(x!=0){
        cout<<ans(x, a, n, c)<<"\n";
        cin>>x>>a>>n>>c;
    }
}
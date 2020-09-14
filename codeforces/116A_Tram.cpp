#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, mx = 0, pIn = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        pIn += b - a;
        if(pIn>mx){
            mx = pIn;
        }
    }
    cout<<mx<<"\n";
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, p, f, cnts, cntw, s, w, ans, tmp, _1, _2;
    cin>>t;
    while(t--){
        cin>>p>>f>>cnts>>cntw>>s>>w;
        if(s<w){
            swap(s, w);
            swap(cnts, cntw);
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}
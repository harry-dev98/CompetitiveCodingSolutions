#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x1, x2, y1, y2;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        int dif1 = abs(x1 - x2);
        int dif2 = abs(y1 - y2);
        if(dif1 && dif2){
            cout<<2+dif1+dif2<<"\n";
        } else {
            cout<<dif1+dif2<<"\n";
        }
    }
    return 0;
}
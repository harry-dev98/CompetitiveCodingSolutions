#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n = 0;
    for(auto ch:s){
        if(ch == '4' || ch == '7')n++;
    }
    bool ans = n>0?true:false;
    while(n){
        if(n%10 != 4 && n%10 != 7){
            ans = false;
            break;
        }
        n/=10;
    }
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}
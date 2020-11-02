#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    string str;
    cin>>t;
    while(t--){
        cin>>a>>b>>str;
        int zeros = 0;
        int ones = 0;
        int ans = 0;
        for(char ch:str){
            if(ch == '0'){
                zeros++;
            } else {
                if(ones == 0){
                    ones = 1;
                    ans += a;
                } else {
                    ans += min(a, b*zeros);
                }
                zeros = 0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
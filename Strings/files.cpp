#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t>>s;
    int x = 0;
    int ans = 0;
    for(auto c:s){
        if(c == 'x'){
            x++;
        }
        else{
            ans += max(0, x-2);
            x = 0;
        }
    }
    ans += max(0, x-2);
    cout<<ans<<"\n";
    return 0;
}
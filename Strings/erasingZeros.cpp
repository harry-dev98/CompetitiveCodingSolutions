#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, one, zero, ans, n;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        one = 0;
        zero = 0;
        ans = 0;
        n = s.length();
        while(s[one]!='1'&&one<n){
            one++;
        }
        for(one; one<n; one++){
            if(s[one]=='0'){
                zero++;
            }
            if(s[one]=='1'){
                ans += zero;
                zero = 0;
            }
        }
        cout<<ans<<"\n";    
    }
    return 0;
}
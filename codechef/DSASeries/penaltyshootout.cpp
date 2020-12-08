#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin>>t;
    string str;
    while(t--){
        cin>>n>>str;
        int f = 0, s = 0, ans = 2*n;
        for(int i=0; i<2*n; i+=2){
            if(str[i] == '1')f++;
            if(str[i+1] == '1')s++;
            if(abs(f-s) > (2*n - (i+2))/2){
                ans = i+2;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    string str;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>str;
        int ones = 0, zeros = 0, qmark = 0;
        bool ans = true;
        for(int i=0; i<n; i++){
            if(str[i%k] == '?'){
                str[i%k] = str[i];
            } else if(str[i] == '?'){
                // pass
            } else {
                if(str[i%k] != str[i]){
                    ans = false;
                    break;
                }
            }
        }
        for(int i=0; i<k; i++){
            if(str[i] == '0')zeros++;
            else if(str[i] == '1')ones++;
            else qmark++;
        }
        if(zeros <= k/2 && ones <= k/2 && ans){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ans = 0;
    char ch = s[0];
    for(int i=1; i<n; i++){
        if(s[i] == ch){
            ans++;
        }
        else{
            ch = s[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
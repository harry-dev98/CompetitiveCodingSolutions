#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    bool ans=false;
    string s1, s2, s3;
    cin>>t;
    while(t--){
        cin>>s1>>s2>>s3;
        n = s1.length();
        ans = true;
        for(int i=0; i<n; i++){
            if(s1[i] != s3[i] && s2[i] != s3[i]){
                ans = false;
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}
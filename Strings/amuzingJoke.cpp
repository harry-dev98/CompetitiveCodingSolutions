#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    int A[26];
    memset(A, 0, sizeof(A));
    for(auto ch:(s1+s2)){
        A[ch-'A']++;
    }
    for(auto ch:s3){
        A[ch-'A']--;
    }
    bool ans = true;
    for(int i=0; i<26; i++){
        if(A[i] != 0){
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
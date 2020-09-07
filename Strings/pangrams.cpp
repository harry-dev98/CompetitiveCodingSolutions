#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int A[26];
    int ans = 0;
    memset(A, 0, sizeof(A));
    for(auto ch:s){
        if(ch >= 'a' && ch<='z'){
            if(A[ch-'a']==0){
                ans++;
            }
            A[ch-'a']++;
        }
        else{
            if(A[ch-'A']==0){
                ans++;
            }
            A[ch-'A']++;
        }
    }
    if(ans==26){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    int A[26];
    cin>>t;
    while(t--){
        memset(A, 0, sizeof(A));
        cin>>s;
        for(auto ch:s){
            A[ch-'a']++;
        }
        int i = 0;
        while(A[i]==0 && i<26){
            i++;
        }
        bool ans = true;
        int zero = 0;
        for(i; i<26; i++){
            if(A[i]>1){
                ans=false;
                break;
            }
            else if(A[i]==0){
                zero++;
            }
            else{
                if(zero>0){
                    ans = false;
                    break;
                }
            }
        }
        cout<<(ans?"Yes":"No")<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ans=0;
    string s1,s2;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s1>>s2;
        bool ans = true;
        int ptr1=-1, ptr2=-1;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                if(ptr1==-1){
                    ptr1 = i;
                }
                else if(ptr2==-1){
                    ptr2 = i;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(s1[ptr1]==s1[ptr2] && s2[ptr1]==s2[ptr2] && ans){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}
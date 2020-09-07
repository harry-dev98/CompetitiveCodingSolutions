#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=1, n = s.length();
    char prev=s[0];
    bool ans = true;
    for(int i=1; i<n; i++){
        if(prev!=s[i]){
            prev = s[i];
            count = 1;
        }
        else{
            count++;
        }
        if(count==7){
            ans=false;
            break;
        }
    }
    cout<<(ans?"NO":"YES")<<"\n";
    return 0;
}
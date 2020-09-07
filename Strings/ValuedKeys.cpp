#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    string ans="";
    bool a = true;
    for(int i=0; i<n; i++){
        if(s1[i]<s2[i]){
            a = false;
            break;
        }
        ans += min(s1[i], s2[i]);
    }
    cout<<(a?ans:"-1")<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2, s="";
    cin>>s1>>s2;
    int n = s1.length();
    for(int i=0; i<n; i++){
        if(s1[i] == s2[i]){
            s += '0';
        }
        else{
            s+= '1';
        }
    }
    cout<<s<<"\n";
    return 0;
}
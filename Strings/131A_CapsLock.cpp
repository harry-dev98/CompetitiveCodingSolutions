#include<bits/stdc++.h>
using namespace std;

char helper(char c, char a){
    int i;
    if(c>='a' && c<='z'){
        i = c-'a';    }
    else{
        i = c - 'A';
    }
    return i+a;
}

int main(){
    string s, ans="";
    cin>>s;
    ans+=helper(s[0], 'A');
    for(int i=1; i<s.length(); i++){
        ans+=helper(s[i], 'a');
    }
    cout<<ans<<"\n";
    return 0;
}
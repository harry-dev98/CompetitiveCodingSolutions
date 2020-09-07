#include<bits/stdc++.h>
using namespace std;

char toUpper(char ch){
    if(ch>='a' && ch<='z'){
            ch = ch - 'a' + 'A';
    }
    return ch;
}
char toLower(char ch){
    if(ch>='A' && ch<='Z'){
            ch = ch - 'A' + 'a';
    }
    return ch;
}

int main(){
    string s;
    cin>>s;
    int up=0, low=0;
    for(auto ch:s){
        if(ch>='a' && ch<='z'){
            low++;
        }
        else{
            up++;
        }
    }
    if( up>low){
        transform(s.begin(), s.end(), s.begin(), toUpper);
    }
    else{
        transform(s.begin(), s.end(), s.begin(), toLower);
    }
    cout<<s<<"\n";
    return 0;
}
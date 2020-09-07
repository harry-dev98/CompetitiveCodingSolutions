#include<bits/stdc++.h>
using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    std::transform(s1.begin(), s1.end(), s1.begin(), asciitolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), asciitolower);
    if(s1>s2){
        cout<<1;
    }
    else if(s1==s2){
        cout<<0;
    }
    else{
        cout<<-1;
    }
    cout<<"\n";
    return 0;
}
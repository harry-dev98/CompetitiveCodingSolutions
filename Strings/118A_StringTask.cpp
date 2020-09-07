#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    string a = "";
    unordered_set<char> S = {0, 4, 8, 14, 20, 24};
    for(auto c:s){
        int c_;
        if(c>='a' && c<='z'){
            c_ = c-'a';
        }
        else{
            c_ = c-'A';
        }
        if(S.find(c_)!=S.end()){
            continue;
        }
        else{
            a+='.';
            a+=c_+'a';
        }
    }
    cout<<a<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int u = 0, l = 0;
    string ansU="", ansL="";
    cin>>str;
    for(auto s: str){
        if('a' <= s && 'z' >= s){
            l++;
            ansU += 'A' + (s - 'a');
            ansL += s;
        }
        else{
            u++;
            ansL += 'a' + (s - 'A');
            ansU += s;
        }
    }
    if(u > l){
        cout<<ansU;
    }
    else{
        cout<<ansL;
    }
    cout<<"\n";
    return 0;
}
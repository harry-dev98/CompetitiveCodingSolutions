#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    bool ans = false;
    unordered_set<string> S = {"ABC", "ACB", "BCA", "BAC", "CAB", "CBA"};
    for(int i=0; i<n-2; i++){
        if(S.find(s.substr(i, 3)) != S.end()){
            ans = true;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}
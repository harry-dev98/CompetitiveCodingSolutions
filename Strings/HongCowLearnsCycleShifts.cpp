#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_set<string> S={s};
    int n=s.length();
    for(int i=0; i<n; i++){
        s = s[n-1] + s.substr(0, n-1);
        S.insert(s);
    }
    cout<<S.size()<<"\n";
    return 0;
}